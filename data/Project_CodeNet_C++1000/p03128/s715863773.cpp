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
int num[]={0,2,5,5,4,5,6,3,7,6};
string judge(string s,string t,char p){
  if(t==".")return s;
  t+=p;
  string res=t;
  int n=s.length();
  int m=t.length();
  bool ss=n>m;
  if(n!=m){
    if(ss)res=s;
    return res;
  }
  rep(i,n){
    if(s[i]==t[i])continue;
    else{
      ss=s[i]>t[i];
      goto FINE;
    }
  }
  FINE:
  if(ss)res=s;
  return res;
}
signed main(){
  int n,m;cin>>n>>m;
  vector<int> a(m);
  rep(i,m)cin>>a[i];
  vector<string> dp(n+1,".");
  vector<pair<int,int>> input(m);
  rep(i,m){
    input[i].second=num[a[i]];
    input[i].first=a[i];
  }
  sort(input.begin(),input.end());
  reverse(ALL(input));
  dp[0]='0';
  rep(i,m){
    rep(j,n+1){
      if(j<input[i].second)continue;
      dp[j]=judge(dp[j],dp[j-input[i].second],(char)(input[i].first+'0'));
    }
  }
  int num=dp[n].length()-1;
  string res;
  rep1(i,num){
    res+=dp[n][i];
  }
  //sort(res.begin(),res.end());
  //reverse(ALL(res));
  //cout<<dp[n]<<"\n";
  cout<<res<<endl;
  return 0;
}
