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
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){ 
    ll n,m;
    cin >> n >> m;
    ll a[m] = {};
    if(m == 1 || n >= m){
        cout << 0 << endl;
        return 0;
    }

    rep(i,0,m){
        cin >> a[i];
    }

    sort(a,a+m);

    ll b[m-1] = {};
    ll ans = 0;
    rep(i,0,m-1){
        b[i] = a[i+1] - a[i]; 
        ans += b[i];
    }

    sort(b,b+m-1,greater<ll>());

    rep(i,0,n-1){
        ans -= b[i];
    }

    cout << ans << endl;

    return 0;
}
