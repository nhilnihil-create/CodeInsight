#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i, m) {
        int k; cin >> k;
        rep(j, k) {
            int ss; cin >> ss;
            s[i].push_back(ss-1);
        }
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    int ans = 0;
    rep(i, (1<<n)) {
        int sum = 0;
        rep(j, m) {
            int l = 0;
            for(auto v : s[j]) if((1<<v) & i) l++;
            if(l % 2 == p[j]) sum++;
        }
        if(sum == m) ans++;
    }
    cout << ans << endl;
}