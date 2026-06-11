#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

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
    }

    ll ans=0;
    for(auto e : m){
        ans+=e.second*(e.second-1)/2;
    }

    cout<<ans<<endl;
}