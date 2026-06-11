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
    ll n;   cin >> n;
    vector<vector<ll>> p(n, vector<ll>(10)), cost(n, vector<ll>(11));

    rep(i, n)   rep(j, 10) cin >> p[i][j];
    rep(i, n)   rep(j, 11) cin >> cost[i][j];
    ll res=-LINF;
    for(int bit=1; bit<(1<<10); bit++){
        ll sum=0;
        vector<ll> open(n, 0);
        rep(i, 10){
            if(bit & 1<<i){
                rep(j, n)   open[j] += p[j][i];
            }
        }
        
        rep(j, n)   sum += cost[j][open[j]];    
        res = max(res, sum);
        
    }
    cout << res << endl;
}
