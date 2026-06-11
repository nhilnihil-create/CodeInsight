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

const int MAXT = 1e5+10;

int main() {
    int n, c; cin >> n >> c;
    vector<vector<int>> vec(c, vector<int>(MAXT, 0));
    rep(i, n) {
        int s, t, c; cin >> s >> t >> c; c--;
        if (vec[c][s]==-1) vec[c][s]++; // 同じチャネルで連続放送
        else {
            s--;
            vec[c][s]++;
        }
        if (vec[c][t-1]) vec[c][t-1]--; // 同じチャネルで連続放送
        else vec[c][t]--;
    }
    // rep(i, c) debug(vec[i]);
    int ans = 0;
    FOR(i, 1, MAXT) {
        int cnt = 0;
        rep(j, c) {
            vec[j][i] += vec[j][i-1];
            cnt += min(1, vec[j][i]);
        }
        chmax(ans, cnt);
    }
    // rep(i, c) debug(vec[i]);
    cout << ans << endl;
}