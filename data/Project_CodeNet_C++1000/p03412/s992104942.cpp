//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=998244353;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b){
  return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b){
  a+=b;
  if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}
 
int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}
 
const int N=2000002;

void solve(){
  int n;
  cin>>n;
  vi a(n);
  cin>>a;
  vi b(n);
  cin>>b;
  int ans=0;
   // (2**i)-1 <x<2**(i+1)
   // 2**i+2**(i+1) <=x
   for(int i=0;i<29;i++){
     vector<int>a2=a,b2=b;
     for(int j=0;j<n;j++){
       a2[j]%=(1<<(i+1));
       b2[j]%=(1<<(i+1));
     }
     sort(all(b2));
     int tot=0;
     for(int j=0;j<n;j++){
       int cnt2=lower_bound(all(b2),(1<<(i+1))-a2[j])-b2.begin();
       cnt2-=(upper_bound(all(b2),(1<<(i))-a2[j]-1)-b2.begin());
       cnt2-=(upper_bound(all(b2),(1<<i)+(1<<(i+1))-a2[j]-1)-b2.begin());
       cnt2+=n;
       tot+=cnt2;
     }
     if(tot&1){
       ans|=1<<i;
     }
     debug(i,tot);
   }
   cout<<ans;
}
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}
