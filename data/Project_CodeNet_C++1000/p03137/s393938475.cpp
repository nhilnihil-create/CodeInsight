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
    vector<ll> x(m);
    rep(i,m) cin>>x[i];

    if(n>=m){
        cout<<0<<endl;
        return 0;
    }

    sort(all(x));
    vector<ll> v;
    ll ans=0;
    rep(i,m-1){
        ans+=x[i+1]-x[i];
        v.push_back(x[i+1]-x[i]);
    }

    sort(all(v));
    reverse(all(v));
    rep(i,n-1){
        ans-=v[i];
    }

    cout<<ans<<endl;
}

