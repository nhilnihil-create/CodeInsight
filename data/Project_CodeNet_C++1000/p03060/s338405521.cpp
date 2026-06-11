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
    ll n;cin >>n;
    ll ans=0;
    vector<ll>v(n);
    vector<ll>c(n);
    for (int i = 0; i < n; ++i) {
        cin >>v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >>c[i];
    }
    for (int i = 0; i < n; ++i) {
        ans+=max(0LL,v[i]-c[i]);
    }
    cout <<ans <<endl;
    return 0;
}