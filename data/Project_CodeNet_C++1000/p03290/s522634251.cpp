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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;


int main(){FIN

    ll d,g;cin>>d>>g;
    vll p(d), c(d);
    REP(i,d) cin>>p[i]>>c[i];
    ll ans = inf;
    for(ll i=0; i<(1<<d);i++){
        // cout<<i<<endl;
        ll cnt=0; 
        ll score=0;
        REP(j,d){
            if((i>>j)&1) {
                score += (j+1)*100*p[j];
                score += c[j];
                cnt += p[j];
            }
        }
        if (score < g){
            REPR(j,d){
                // if (i==16) cout<<j<<endl;
                if (!((i>>j)&1)) {
      
                    if (g-score > p[j]*(j+1)*100) cnt += mod;
                    cnt += (g-score) / (100*j+100);
                    if ((g-score) % ((100*j+100))) cnt++;
                    break;
                }
            }
        } 
        // cout<<i<<' '<<score<<' '<<cnt<<endl;
        ans = min(ans, cnt);
    }
    
    cout<<ans<<endl;
    return 0;
}