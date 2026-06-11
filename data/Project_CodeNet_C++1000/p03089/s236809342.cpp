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
    ll n;
    cin >> n;
    vector<ll> vec;
    rep(i,0,n){
        ll a;
        cin >> a;
        vec.push_back(a);
    }
    vector<ll> ans;
    rep(i,0,n){
        rep(j,0,vec.size()){
            ll k = vec.size()-j-1;
            if(k+1 == vec[k]){
                ans.push_back(vec[k]);
                vec.erase(vec.begin()+k);
                break;
            }
        }
    }
    
    if(ans.size() != n) cout << -1 << endl;
    else{
        rep(i,0,ans.size()){
            ll k = ans.size()-i-1;
            cout << ans[k] << endl;
        }
    }
    return 0;
}
