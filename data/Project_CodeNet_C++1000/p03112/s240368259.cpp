#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,q;cin >> a >> b >> q;
    vector<ll> s(a+2),t(b+2);
    s[0]=-INF,t[0]=-INF;
    s[a+1]=INF,t[b+1]=INF;
    REP(i,a){
        cin >> s[i+1];
    }
    REP(i,b){
        cin >> t[i+1];
    }
    REP(i,q){
        ll x;cin >> x;
        int u=lower_bound(ALL(s),x)-s.begin();
        int v=lower_bound(ALL(t),x)-t.begin();
        ll ans=INF;
        REP(j,2){
            REP(k,2){
                int p=u-j,q=v-k;
                chmin(ans,abs(s[p]-x)+abs(t[q]-s[p]));
                chmin(ans,abs(t[q]-x)+abs(s[p]-t[q]));
            }
        }
        cout << ans << endl;
    }
}