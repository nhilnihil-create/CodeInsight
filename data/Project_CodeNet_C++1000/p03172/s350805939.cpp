#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n, k;    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    rep(i, n+1) dp[i][0] = 1;
    rep(i, n){
        rep(j, k){
            dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j];
            dp[i+1][j+1] %= MOD;
            if(0<=j-a[i]){
                dp[i+1][j+1] += MOD-dp[i][j-a[i]];
                dp[i+1][j+1] %= MOD;
            }
        }
    }
    cout << dp[n][k] << endl;
}
