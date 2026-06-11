#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define INF (int)(1e9)

int N;
const int MAX_N = 100010;

int dist[MAX_N];
bool chk[MAX_N];

struct state{
    int d,v;
    bool operator<(const state& r)const{
        return d > r.d;
    }
};
priority_queue<state> Q;

void go(int u,int c){
    if(dist[u] > c){
        dist[u] = c;
        Q.push(state{dist[u], u});
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        dist[i] = INF;
    }
    dist[1] = 1;

    Q.push(state{dist[1], 1});
    int v,d;
    while(!Q.empty()){
        state here = Q.top();
        Q.pop();
        v = here.v;
        d = here.d;
        if(chk[v])continue;
        chk[v] = 1;
        
        go((v+1)%N, d+1);
        go((v*10)%N, d);
    }
    printf("%d\n",dist[0]);
    return 0;
}
    
