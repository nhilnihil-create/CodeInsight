#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    vector<ll> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+a[i];

    map<ll,ll> m;
    rep(i,n+1){
        m[s[i]]++;
        //cout<<s[i]<<" ";
    }
    //cout<<endl;
    ll ans=0;
    for(auto e : m){
        ll x=e.second;
        ans+=x*(x-1)/2;
    }

    cout<<ans<<endl;
}
    


