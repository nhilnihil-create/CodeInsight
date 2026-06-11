#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int x[100009];
bool vs[100009];
vector<pii> adj[100009];

void go(int now) {
    vs[now] = 1;
    for(auto& it: adj[now]) {
        if(!vs[it.first]) {
            x[it.first] = x[now] + it.second;
            go(it.first);
        }
    }
}

int main() {
    int N, M; scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++) {
        int L, R, D; scanf("%d%d%d",&L,&R,&D);
        adj[L].push_back({R, D});
        adj[R].push_back({L, -D});
    }
    for(int i=1; i<=N; i++) if(!vs[i]) go(i);
    for(int i=1; i<=N; i++) {
        for(auto& it: adj[i]) {
            if(x[i] + it.second != x[it.first]) return !printf("No");
        }
    }
    puts("Yes");
    return 0;
}
