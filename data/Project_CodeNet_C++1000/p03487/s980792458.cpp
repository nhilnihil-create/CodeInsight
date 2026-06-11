#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll n;
    cin>>n;
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        m[a]++;
    }
    ll ans=0;
    for(auto x:m){
        if(x.second<x.first) ans+=x.second;
        else ans+=x.second-x.first;
    }
    cout<<ans<<endl;
}