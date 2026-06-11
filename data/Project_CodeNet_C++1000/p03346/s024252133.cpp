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
    vector<int> a(n);
    rep(i, n) {cin >> a[i]; a[i]--;}
    vector<int> b(n);
    rep(i, n) {
        int num = a[i];
        b[num] = i;
    }

    debug(b);
    int cur = -1;
    int cnt = -1;
    int max = 0;
    rep(i, n-1) {
        if (cur==-1) {
            cur = b[i];
            cnt = 1;
        }
        if (cur<b[i+1]) {
            cnt++;
            cur = b[i+1];
        }
        else cur = -1;
        chmax(max, cnt);
    }
    int ans = 0;
    if (n>1) ans = n-max;
    cout << ans << endl;
}