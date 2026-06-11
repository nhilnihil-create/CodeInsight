#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cstdio>

using namespace std;

const int N = 100010;

int n;

int dist[N];
deque<int> dq;

inline void Update(int u, int v, int w){
    if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        if(w) dq.push_back(v);
        else dq.push_front(v);
    }
    return;
}

void Dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 1;
    dq.push_back(1);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        Update(u, (u+1) % n, 1);
        Update(u, u*10%n, 0);
    }
    return ;
}

int main(){
    scanf("%d", &n);
    Dijkstra();
    printf("%d\n", dist[0]);
    return 0;
}
