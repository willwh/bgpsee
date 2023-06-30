#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <pthread.h>

//Static number of BGP peers for the moment;
#define MAX_BGP_PEERS 256

struct bgp_peer;
struct bgp_instance;
struct bgp_local;

struct bgp_instance *create_bgp_instance(uint16_t,  uint32_t, uint8_t);
void free_bgp_instance(struct bgp_instance *);

unsigned int create_bgp_peer(struct bgp_instance *, const char *, const uint16_t, const char *);
void free_bgp_peer(struct bgp_instance *, unsigned int);

int activate_bgp_peer(struct bgp_instance *, unsigned int);
int deactivate_bgp_peer(struct bgp_instance *, unsigned int);