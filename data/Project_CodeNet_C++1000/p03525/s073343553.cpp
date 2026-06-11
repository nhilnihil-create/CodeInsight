#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int n;
int num[13]={};
int s=0;
int calc(vector<int> const& status,vector<int> const& d){
  int res=inf;
  vector<int> buf={0,24};
  rep1(i,12){
    if(status[i]==1){
      buf.push_back(i);
    }
    else if(status[i]==2){
      buf.push_back(24-i);
    }
    else if(status[i]==3){
      buf.push_back(i);
      buf.push_back(24-i);
    }
  }
  sort(ALL(buf));
  int num=buf.size()-1;
  rep1(i,num){
    res=min(buf[i]-buf[i-1],res);
  }
  if(res==inf)res=0;
  return res;
}
int solve(vector<int> status,vector<int> const& d,int cur){
  int res=0;
  if(cur==13)return calc(status,d);
  else{
    if(num[cur]==0)res=solve(status,d,cur+1);
    if(num[cur]==1){
      status[cur]=1;
      res=max(res,solve(status,d,cur+1));
      status[cur]=2;
      res=max(res,solve(status,d,cur+1));
    }
    if(num[cur]>=2){
      status[cur]=3;
      res=max(res,solve(status,d,cur+1));
    }
  }
  return res;
}
signed main(){
  cin>>n;
  vector<int> d(n);
  rep(i,n)cin>>d[i];
  sort(ALL(d));
  d.push_back(inf);
  rep(i,n){
    num[d[i]]++;
  }
  /*int cur=1;int last=d[0];
  rep1(i,n){
    if(d[i]==last){
      cur++;
    }
    else{
      num[last]=cur;
      last=d[i];
    }
  }*/
  vector<int> status(13,0);
  int res=solve(status,d,1);
  if(num[0]>0)res=0;
  rep1(i,12){
    if(num[i]>=3)res=0;
  }
  if(num[12]>=2)res=0;
  cout<<res<<endl;
  return 0;
}
