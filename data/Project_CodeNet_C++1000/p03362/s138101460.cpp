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
    bool isprime[55556] = {};
    rep(i,2,55556) isprime[i] = true;

    for(ll i = 2; i * i < 55556; i++){
        for(ll j = i; i * j < 55556; j++){
            isprime[i*j] = false;
        }
    }

    vector<ll> primelist;
    rep(i,0,55556) if(isprime[i] && i % 5 == 1) primelist.push_back(i);

    rep(i,0,n){
        cout << primelist[i] << ((i != n-1)?" ":"\n");
    }
}
