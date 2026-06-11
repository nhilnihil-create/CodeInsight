#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll N,M;cin>>N>>M;
  vector<int> A(M);rep(i,M)cin>>A[i];
  int stick[10]{0,2,5,5,4,5,6,3,7,6};
  vector<bool> flag(10,false);
  rep(i,M)flag[A[i]]=true;
  for(int i=0;i<M-1;++i)for(int j=i+1;j<M;++j){
    if(stick[A[i]]==stick[A[j]]){
      if(A[i]>A[j]) flag[A[j]]=false;
      else flag[A[i]]=false;
    }
  }
  flag[0]=false;
  vector<pair<int,int>> num;
  rep(i,10){
    if(flag[i]){num.emplace_back(i,stick[i]);}
  }
  int dp[20000];
  fill(dp,dp+20000,-1e9);
  sort(all(num),[&](auto const& a,auto const& b){return a.first>b.first;});
  dp[0]=0;
  rep(i,10010){
    rep(j,num.size()){
      dp[i+num[j].second] = max(dp[i+num[j].second],dp[i]+1);
    }
  }
  int tmp=N;
  vector<int> v;
  while(tmp>0){
    rep(i,num.size()){
      //cout << "loopcheck i" << i << num[i].first << endl;
      if(tmp-num[i].second>=0 && dp[tmp-num[i].second] == dp[tmp]-1){
        tmp -= num[i].second;
        v.push_back(num[i].first);
        break;
      }
    }
  }
  //rep(i,20)cout<<"i " << i << "dp " << dp[i] << endl;
  sort(all(v),greater<int>());
  rep(i,v.size()) cout<<v[i];
  cout<<endl;
}