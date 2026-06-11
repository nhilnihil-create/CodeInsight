#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll a;
        cin>>a;
        v.push_back({a,1});
    }
    rep(i,m){
        ll b,c;
        cin>>b>>c;
        v.push_back({c,b});
    }

    sort(all(v));
    reverse(all(v));
    ll ans=0,cnt=0;
    rep(i,v.size()){
        if(cnt+v[i].second>=n){
            ans+=(n-cnt)*v[i].first;
            cout<<ans<<endl;
            return 0;
        }

        ans+=v[i].first*v[i].second;
        cnt+=v[i].second;
    }
}
