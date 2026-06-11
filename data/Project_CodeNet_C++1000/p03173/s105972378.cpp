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
ll dp[440][440], flag[440][440], cum[440];
ll calc(int l, int r){
    if(flag[l][r]) return dp[l][r];
    flag[l][r] = 1;
    if(l==r) return 0;
    ll res = LINF;
    FOR(i, l, r)
        res = min(res, calc(l, i)+calc(i+1, r));
    return dp[l][r] = res +cum[r]-cum[l-1];
}


int main(){
    ll n;   cin >> n;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        cum[i+1] = cum[i]+a[i];
    }
    
    calc(0, n);
    cout << dp[1][n] << endl;

}
