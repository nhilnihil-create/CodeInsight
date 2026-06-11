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

const ll MOD = 1e9+7;

int main(){

    ll n;
    cin >> n;
    ll a[n] = {};
    rep(i,0,n) cin >> a[i];
    map<ll,ll> m;

    rep(i,0,n){
        if(m.count(a[i]-1) == 0){
            m[a[i]] = 1;
        }
        else{
            m[a[i]] = m[a[i]-1] + 1;
        }
    }

    ll memo = 0;
    rep(i,0,n){
        memo = max(memo,m[i+1]);
    }

    cout << n - memo << endl;
}
