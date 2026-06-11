#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,m,q;cin >> n >> m >> q;
    vl s(n+2), t(m+2), x(q);
    s[0] = -LINF, t[0] = -LINF;
    s[n+1] = LINF, t[m+1] = LINF;
    rep(i,n) cin >> s[i+1];
    rep(i,m) cin >> t[i+1];
    rep(i,q) cin >> x[i];

    for(auto& r : x){
        ll ans = LINF;
        int ns[2], nt[2];
        ns[0] = lower_bound(s.begin(),s.end(),r) - s.begin();
        nt[0] = lower_bound(t.begin(),t.end(),r) - t.begin();
        ns[1] = ns[0] -1;
        nt[1] = nt[0] -1;

        rep(i,2) rep(j,2){
            chmin(ans, abs(r - s[ns[i]]) + abs(s[ns[i]] - t[nt[j]]));
        }

        rep(j,2) rep(i,2){
            chmin(ans, abs(r - t[nt[j]]) + abs(t[nt[j]] - s[ns[i]]));
        }
        cerr << "ans is ";
        cout << ans << endl;
    }
}