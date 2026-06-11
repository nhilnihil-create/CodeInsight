#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

ll f(ll x){
    if(x%2==1)return 3*x+1;
    return x/2;
}

int main(){
   ll s;cin >>s;
   map<ll,int>mp;
   ll i=1;
   while(1){
       mp[s]++;
       if(mp[s]>=2){
           break;
       }
       s=f(s);
       i++;
   }
   cout <<i<<endl;
   return 0;
}