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
    ll n;cin>>n;
    vll c(n-1), s(n-1), f(n-1);
    REP(i,n-1){
        cin>>c[i]>>s[i]>>f[i];
    }
    FOR(i,0,n-2){
        ll sum = c[i] + s[i];
        FOR(j, i+1, n-2){
            if (sum < s[j]) sum = s[j]+c[j];
            else{
                sum += (f[j]- (sum % f[j])) % f[j];
                sum += c[j];
            }
        }
        cout<<sum<<endl;
    }
    cout<<0<<endl;
    return 0;
}
