#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int INF=1e9;
//const int MOD=998244353;
const long long LINF=1e18;
//template
int N,now,T=200001;
map<int,int> ma;
int dpw[11][200001];
std::vector<int> v(T),w(T),dp(T),subma(T);//w[i]はi番目のmapのそれの容量
/*
v[i-1]<v[i]の場合はその分だけ0を付け足せばいい
v[i-1]==V[i]の場合は末尾に1を追加 mになろうとしたら1繰り上げて本人は0になる
v[i-1]>v[i]の場合は削ってから末尾に1を追加

0文字目に入ってきたらout

このままだと1e9個の容量を用意する必要があるので考える
mapで座圧して容量を差で考える
例えばv[i]で6の次に大きい数が9の場合、９のやつが容量pw(3,m)を持つと考える
*/
set<int> s;
int pw(int n,int k){
  if(k<0)return INF;
  if(n<=10)return dpw[n][k];
  if(k>9)return INF;
  int res=1;
  while(k--){
    res*=n;
    if(res>100000000)return INF;
    if(res<0)return INF;
  }
  return res;
}
bool can(int m){
  for(auto i=s.begin();i!=s.end();i++)dp[*i]=0;s.clear();
  /*
  if(m<=5){
    cout<<m<<":";for(int j=0;j<=5;j++)cout<<dp[j]<<" ";cout<<endl;
    for(auto p:s)cout<<p<<" ";cout<<endl;
  }
  */
  //if(m<=5)cout<<m<<":";
  //if(m<=5)for(int j=0;j<=10;j++)cout<<dp[j]<<" ";cout<<endl;
  for(int j=1;j<N;j++){
    if(v[j]>v[j-1]){
      for(auto i=s.upper_bound(subma[j-1]);i!=s.end();){
        dp[*i]=0;i=s.erase(i);
      }
    }
    else{
      dp[subma[j]]++; now=subma[j];
      while(dp[now]==pw(m,w[now])){
        dp[now]=0;s.erase(now);
        dp[--now]++;
      }
      s.insert(now);
    }
    /*
    if(m<=5){
      cout<<m<<":";for(int j=0;j<=5;j++)cout<<dp[j]<<" ";cout<<endl;
      for(auto p:s)cout<<p<<" ";cout<<endl;
    }
    */
    if(dp[0])return false;
  }
  return true;
}
//main
signed main(){
  cin>>N;
  for(int i=0;i<N;i++)cin>>v[i];
  bool f=true;for(int i=1;i<N;i++)if(v[i]<=v[i-1])f=false;if(f){cout<<1<<endl;return 0;}
  for(int i=0;i<N;i++)ma[v[i]]=0;
  ma[0]=0;int tmp=-1;int cnt=0;
  for(auto &p:ma){
    if(~tmp)w[cnt]=p.first-tmp;
    tmp=p.first;
    p.second=cnt++;
  }
  for(int i=0;i<N;i++)subma[i]=ma[v[i]];
  w[0]=-1;
  for(int i=2;i<=10;i++){
    dpw[i][0]=1;
    for(int j=1;j<T;j++){
      dpw[i][j]=min(10000000,dpw[i][j-1]*i);
      if(dpw[i][j]==10000000){
        for(int k=j+1;k<T;k++)dpw[i][j]=10000000;
        continue;
      }
    }
  }
  int l=1,r=N+2,m;
  while(r-l>1){
    m=(l+r)>>1;
    if(can(m))r=m;
    else l=m;
  }
  cout<<r<<endl;
}
