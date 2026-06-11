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

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){

    ll n,c;
    cin >> n >> c;
    
    ll d[c][c] = {};
    rep(i,0,c) rep(j,0,c) cin >> d[i][j];
    
    ll grid[n][n];
    rep(i,0,n) rep(j,0,n) cin >> grid[i][j];

    ll sum[3][c];
    rep(i,0,3) rep(j,0,c) sum[i][j] = 0; 

    rep(i,0,n){
        rep(j,0,n){
            ll temp = (i+1+j+1)%3;
            rep(k,0,c){
                sum[temp][k] += d[grid[i][j]-1][k];
            }
        }
    }

    ll ans = LINF;
    rep(i,0,c){
        rep(j,0,c){
            if(i == j) continue;
            rep(k,0,c){
                if(i == k || j == k) continue;
                ll temp = sum[0][i] + sum[1][j] + sum[2][k];
                ans = min(temp,ans);
            }
        }
    }
    cout << ans << endl;

    return 0;
}


