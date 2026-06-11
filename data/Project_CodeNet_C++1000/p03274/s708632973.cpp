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
   ll n,k;cin >>n>>k;
   vector<ll>l;
   vector<ll>r;
   l.push_back(0);
   r.push_back(0);
    for (int i = 0; i < n; ++i) {
        ll x;cin >>x;
        if(x<0)l.push_back(-x);
        else r.push_back(x);
    }
    for (int i = 0; i <= k; ++i) {
        r.push_back(INF);
        l.push_back(INF);
    }
    sort(all(l));
    ll ans=INFll;
    for (int i = 0; i <=k; ++i) {
        ans=min(2*r[i]+l[k-i],ans);
        ans=min(2*l[i]+r[k-i],ans);
    }
    cout <<ans <<endl;
   return 0;
}