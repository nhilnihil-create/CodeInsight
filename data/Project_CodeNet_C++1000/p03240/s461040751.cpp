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

    ll n; cin>>n;
    vll x(n), y(n), h(n);
    REP(i,n) cin>>x[i]>>y[i]>>h[i];
    // REP(i,3)cout<<x[i]<<endl;
    ll high=0;
    REP(i,101){
        REP(j,101){
            REP(k,n){
                // if(i==100 && j==0) cout<<h[k]<<endl;
                if (h[k]==0) continue;
                else{
                    high = h[k] + abs(i-x[k]) + abs(j-y[k]);
                    
                    break;
                }
            }
            bool ok = true;
            REP(k,n){
                ll part = high - abs(i-x[k]) - abs(j-y[k]);
                if (h[k]>0 && part != h[k]) ok = false;
                else if (h[k]==0 && part > 0) ok = false;
            }
            if (ok) {
                cout<<i<<' '<<j<<' '<<high<<endl;
                // cout<<"asssssss"<<endl;
                return 0;
            }
        }
    }
    return 0;
}