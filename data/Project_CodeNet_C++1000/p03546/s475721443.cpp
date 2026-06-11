#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    int cost[10][10]; rep(i,10) rep(j,10) cin >> cost[i][j];
    int data[h][w]; rep(i,h) rep(j,w) cin >> data[i][j];

    rep(k,10) rep(i,10) rep(j,10) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    ll ans = 0;

    rep(i,h) rep(j,w) {
        if(abs(data[i][j]) == 1) continue;
        ans += cost[data[i][j]][1];
    }
    cout << ans << endl;
}

