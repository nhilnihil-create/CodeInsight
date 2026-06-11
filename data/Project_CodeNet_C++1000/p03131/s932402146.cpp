#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   ll k,a,b;cin>>k>>a>>b;
   ll ans=1;
   if(ans<a){
       ans+=min(a-1,k);
       k-=min(a-1,k);
   }
   if(b-a>2){
       ans+=(b-a)*(k/2);
       k%=2;
       ans+=k;
   }
   else {
       ans+=k;
   }
   cout <<ans <<endl;
}