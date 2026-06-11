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
    ll n,k;
    cin >> n >> k;
    ll v[n] = {};
    rep(i,0,n) cin >> v[i];

    ll ans = 0;
    rep(i,1,min(k,n)+1){ // いくつ宝石を取るか
        rep(j,0,i+1){ //いくつ左から取るか
            vector<ll> vec;
            rep(l,0,n){
                if(l < j || n-1-(i-j) < l) vec.push_back(v[l]);
            }
            sort(vec.begin(),vec.end());
            ll sum = 0,cnt = 0;
            rep(l,0,vec.size()){
                if(cnt < (k-i) && vec[l] < 0){
                    cnt++;
                }
                else{
                    sum += vec[l];
                }
            }
            ans = max(sum,ans);
        }
    }
    cout << ans << endl;
}


