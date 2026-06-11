#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int WHITE = 0;
const int BLACK = 1;
vector<pair<int, int>> V[MAX];
int color[MAX], d[MAX], N;

void dfs_visit(int u, bool& flg) {
    color[u] = BLACK;
    for (int i = 0; i < V[u].size(); i++) {
        int v, w;
        v = V[u][i].first;
        w = V[u][i].second;
        if (color[v] == BLACK && d[v] != d[u] + w) flg =  false;
        if (color[v] == WHITE) {
            d[v] = d[u] + w;
            dfs_visit(v, flg);
        }
    }
}

bool dfs() {
    for (int i = 0; i < N; i++) color[i] = WHITE;
    bool flg = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == WHITE) {
            d[i] = 0;
            dfs_visit(i, flg);
        } 
    }
    return flg;
}

int main() {
    int M, L, R, D;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &L, &R, &D);
        V[L].push_back(make_pair(R, D));
        V[R].push_back(make_pair(L, -D));
    }
    bool flg = dfs();
    if (flg) printf("Yes\n");
    else printf("No\n");
    return 0;
}