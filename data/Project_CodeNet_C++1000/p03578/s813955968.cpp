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
   vector<ll>d(n);
   map<ll,int>mp;
    for (int i = 0; i < n; ++i) {
        cin >>d[i];
        mp[d[i]]++;
    }
   ll m;cin >>m;
   bool flg=true;
    for (int j = 0; j < m; ++j) {
        ll t;cin >>t;
        if(mp[t]==0)flg=false;
        else {
            mp[t]--;
        }
    }
   if(flg)puts("YES");
   else puts("NO");
   return 0;
}