#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

ll dp[1<<16];

int main() {
    int n; cin >> n;
    vvint a(n,vint(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    for (int s = 1; s < 1<<n; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s>>i & s>>j & 1) dp[s] += a[i][j];
            }
        }
        for (int t = s; t > 0; t = (t-1)&s) {
            if (t == s) continue;
            chmax(dp[s],dp[t]+dp[t^s]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
}