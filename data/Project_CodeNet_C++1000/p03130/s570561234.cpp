#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int graph[4][4];
bool visited[4];

bool all_vis(int cur) {
    visited[cur] = true;

    for(int i = 0; i < 4; ++i) if(graph[cur][i]) {
        if(visited[i]) continue;
        if(all_vis(i)) return true;
    }

    for(int i = 0; i < 4; ++i) if(!visited[i]) {
        visited[cur] = false;
        return false;
    }
    visited[cur] = false;
    return true;
}

bool tansaku() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) visited[i] = false;
        if(all_vis(i)) return true;
    }
    return false;
}

int main()
{
    for(int i = 0; i < 3; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a][b] = graph[b][a] = 1;
    }
    if(tansaku()) printf("YES\n");
    else printf("NO\n");
    return 0;
}