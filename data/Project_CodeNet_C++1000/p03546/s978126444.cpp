#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    int cs[10][10];
    rep(i, 10) {
        rep(j, 10) cin >> cs[i][j];
    }
    vector<vector<int>> as(h, vector<int>(w, 0));
    rep(i, h) rep(j, w) cin >> as[i][j];
    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                cs[i][j] = min(cs[i][j], cs[i][k] + cs[k][j]);
            }
        }
    }
    int ret = 0;
    rep(i, h) {
        rep(j, w) {
            if (as[i][j] == -1 || as[i][j] == 1) continue;
            ret += cs[as[i][j]][1]; 
        }
    }
    cout << ret << endl;
    return 0;
}