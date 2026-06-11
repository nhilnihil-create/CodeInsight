#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    ll n,h; cin>>n>>h;
    priority_queue<pair<ll,ll>> v;
    rep(i,0,n){
        ll x,y; cin>>x>>y;
        v.push(make_pair(x,0));
        v.push(make_pair(y,1));
    }
    ll res=h;
    ll ans=0;
    while(!v.empty()){
        if(v.top().second==0){
            cout<<ans+(ll)ceil((res+0.0)/v.top().first)<<endl;
            return 0;
        }else{
            res-=v.top().first;
            ans++;
            v.pop();
            if(res<=0){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
}