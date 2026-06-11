//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//素因数分解O(√n)
map<ll,ll>prime_factor(ll n){
  map<ll,ll>res;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      res[i]++;
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}
int main(){
  ll n;cin>>n;
  map<ll,ll>M;
  for(ll i=1;i<=n;i++){
    map<ll,ll>M2=prime_factor(i);
    for(auto p:M2){
      M[p.first]+=p.second;
    }
  }
  map<ll,ll>ans;
  for(auto p:M){
    if(2<=p.second)ans[2]++;
    if(p.second>=4)ans[4]++;
    if(p.second>=14)ans[14]++;
    if(p.second>=24)ans[24]++;
    if(p.second>=74)ans[74]++;
  }
  ll last=0;
  last+=ans[4]*(ans[4]-1)/2*(ans[2]-ans[4]);
  last+=ans[4]*(ans[4]-1)*(ans[4]-2)/2;//2個と4個と4個のとき２つ区別できるから２！で割る
  last+=ans[14]*(ans[4]-1);
  last+=ans[24]*(ans[2]-1);
  last+=ans[74];
  cout<<last<<endl;
}