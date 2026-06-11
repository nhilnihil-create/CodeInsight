/*
    Problem 62
    https://atcoder.jp/contests/abc079/tasks/abc079_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int H, W;
    cin >> H >> W;
    int V = 10;
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> G[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (G[i][k] == INF) continue;
            for (int j = 0; j < V; j++) {
                if (G[k][j] == INF) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int num;
            cin >> num;
            if (num == -1) continue;
            ans += G[num][1];
        }
    }
    cout << ans << '\n';
}