#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> G[100000];
int color[100000];
int white = 0;

bool dfs(int v, int c) {
    color[v] = c;
    if (c == 1) white++;
    for (int i = 0; i < G[v].size(); i++) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

int main()
{   
    memset(color, 0, 100000);
    ll N, M;
    cin >> N >> M;
    for (ll i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; 
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (dfs(0,1)) {cout << white*(N-white) - M << endl;} 
    else {cout << N*(N-1)/2 - M << endl;}
    return 0;
}