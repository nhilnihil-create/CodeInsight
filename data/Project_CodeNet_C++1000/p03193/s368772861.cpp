#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,h,w;cin >>n>>h>>w;
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        ll a,b;cin>>a>>b;
        if(a>=h&&b>=w)ans++;
    }
    cout <<ans <<endl;
    return 0;
}