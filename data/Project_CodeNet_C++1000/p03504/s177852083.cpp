#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

ll imos[30][200002] = {};
int main(){
    ll n,m;
    cin >> n >> m;
   
    
    rep(i,0,n){
        ll a,b,c;
        cin >> a >> b >> c;
        imos[c-1][2*a-1]++;
        imos[c-1][2*b]--;
    }
    rep(i,0,30) rep(j,1,200002) imos[i][j] += imos[i][j-1];
    rep(i,0,30) rep(j,0,200002) imos[i][j] = min(1LL,imos[i][j]);

    ll ans = 0;
    rep(i,0,200002){
        ll cnt = 0;
        rep(j,0,30){
            cnt += imos[j][i];
        }
        ans = max(cnt,ans);
    }
    cout << ans << endl;
    return 0;
}