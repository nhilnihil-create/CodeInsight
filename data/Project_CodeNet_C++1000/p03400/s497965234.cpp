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
    ll n,d,x;cin >>n>>d>>x;
    ll ans=x;
    for (int i = 0; i < n; ++i) {
        ll a;cin >>a;
        ans++;
        ll c=d;
        c--;
        ans+=c/a;
    }
    cout <<ans<<endl;
    return 0;
}