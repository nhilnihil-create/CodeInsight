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

ll s[100050], t[100050], c[100050];
ll tt[100050], sm[100050];
int main(){FIN
    ll n,cha;cin>>n>>cha;
    REP(i,n){
        cin>>s[i]>>t[i]>>c[i];
    }
    FOR(i,1,cha){
        REP(j,100050) tt[j]=0;
        REP(j,n) if(c[j]==i) {
            tt[s[j]]++; 
            tt[t[j]+1]--;
        }
        REP(j,100050) tt[j] += tt[j-1];
        REP(j,100050) if(tt[j]) sm[j]++;
    }
    // REP(i,10) cout<<sm[i];
    // cout<<endl;
    ll mx=0;
    REP(i,100050) mx = max(mx, sm[i]);
    cout<<mx<<endl;
    return 0;
}
