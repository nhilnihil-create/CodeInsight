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
    
    ll a,b,k;
    cin >> k >> a >> b;
    ll ans = 1;
    if(b - a > 1 && k > a){
        k -= (a-1); ans = a;
        if(k % 2 == 1) ans += 1;
        ans += (b-a)*(k/2);
        cout << ans << endl;
    }
    else{
        cout << 1 + k << endl;
    }

    return 0;
}