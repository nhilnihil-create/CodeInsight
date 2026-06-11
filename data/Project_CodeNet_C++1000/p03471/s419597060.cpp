#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main(){FIN
    ll n,y;cin>>n>>y;
    ll mx = y / 10000;
    REP(i, mx+1){
        ll n2 = n;
        ll y2 = y;
        n2 -= i;
        y2 -= 10000 * i;
        ll mx2 = y2 / 5000;
        REP(j, mx2+1){
            ll n3 = n2;
            ll y3 = y2;
            n3 -= j;
            y3 -= 5000 * j;
            if (n3 * 1000 == y3) {
                cout<<i <<' '<<j<<' '<<n3<<endl;
                return 0;
            }
        }   
    }
    cout<<-1<<' '<<-1<<' '<<-1<<endl;
    return 0;
}
