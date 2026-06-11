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
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n, k;    cin >> n >> k;
    vector<ll> dp(k+1, 0), a(n);
    rep(i, n)   cin >> a[i];
    
    rep(i, k+1){
        rep(j, n){
            if(a[j]<=i && dp[i-a[j]]==0) dp[i] = 1;
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}
