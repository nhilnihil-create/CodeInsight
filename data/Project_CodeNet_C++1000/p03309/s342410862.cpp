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
   vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        ll x;cin>>x;
        x-=(i+1);
        a[i]=x;
    }
   sort(all(a));
    ll b=a[n/2];
   ll ans=0;
    for (int i = 0; i < n; ++i) {
        ans+=abs(a[i]-b);
    }
    cout <<ans <<endl;
   return 0;
}