#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
const int INF=1e+9;
const ll INFLL=1e+17;
ll K;
vl snuke,snuke_ans,snuke2;
ll digit_sum(ll x){
  ll res=0;
  while(x>=10){
    res+=x%10;
    x/=10;
  }
  res+=x;
  return res;
}
double snuke_num(ll x){
  return (double)(x)/(double)(digit_sum(x));
}
void make_snuke(){
  rep1(i,9) snuke.push_back(i);
  rep1(i,9) snuke.push_back(i*10+9);
  ll x=100;
  rep(i,13){
    for(ll j=2;j<=200;j++){
      snuke.push_back(j*x-1);
    }
    x*=10;
  }
  std::sort(snuke.begin(),snuke.end());
  int ss=snuke.size();
  snuke.push_back(0);
  rep(i,ss){
    if(snuke[i]!=snuke[i+1]) snuke2.push_back(snuke[i]);
  }
  double min=1e+16;
  for(ll i=snuke2.size()-1;i>=0;i--){
    if(snuke_num(snuke2[i])<=min){
      min=snuke_num(snuke2[i]);
      snuke_ans.push_back(snuke2[i]);
    }
  }
  std::sort(snuke_ans.begin(),snuke_ans.end());  
}
void solve(){
  make_snuke();
  rep(i,K) prin(snuke_ans[i]);
}
int main(){
  cin>>K;
  solve();
  return 0;
}
