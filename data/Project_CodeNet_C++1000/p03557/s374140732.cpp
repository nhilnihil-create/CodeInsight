#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int main(){
    int n;  cin >> n;
    vector<ll> a(n), b(n), c(n);
    REP(i, n)   cin >> a[i];
    REP(i, n)   cin >> b[i];
    REP(i, n)   cin >> c[i];
    sort(ALL(a));   sort(ALL(c));   sort(ALL(b));

    ll res=0;
    REP(i, n){
        ll x = b[i];
        auto top = lower_bound(ALL(a), x);
        auto bottom = upper_bound(ALL(c), x);
        if(top!=a.begin() && bottom!=c.end()){
            res += (top-a.begin())*(n-(bottom-c.begin()));
        } 
    }
    cout << res << endl;
}
