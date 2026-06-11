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
   ll n,X;cin >>n>>X;
   vector<ll>x(n);
   vector<ll>d(n);
    for (int i = 0; i < n; ++i) {
        cin >>x[i];
        d[i]=abs(X-x[i]);
    }
    ll g=0;
    for (int i = 0; i < n; ++i) {
        g=__gcd(g,d[i]);
    }
    cout <<g<<endl;
   return 0;
}