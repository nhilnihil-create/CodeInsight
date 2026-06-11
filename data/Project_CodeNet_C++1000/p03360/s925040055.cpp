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
    ll a,b,c;cin >>a>>b>>c;
    ll k;cin >>k;
    ll ans=a+b+c;
    ll mx=max({a,b,c});
    for (int i = 0; i < k; ++i) {
        ans+=mx;
        mx+=mx;
    }
    cout <<ans <<endl;
    return 0;
}