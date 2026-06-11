#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    int remove = n/2*2-1;
    rep(i, n) {
        FOR(j, i+1, n) {
            if (j == remove) continue;
            G[i].push_back(j);
        }
        remove--;
    }
    print(G);
    int cnt = 0;
    rep(i, n) cnt += sz(G[i]);
    cout << cnt << endl;
    rep(i, n) {
        rep(j, sz(G[i])) cout << i+1 << " " << G[i][j]+1 << endl;
    }
}