#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
deque<int> deq;
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

ll dp[4][100005];

int main(){
  string s;
  cin >> s;
  int n=s.size();
  dp[0][0]=1;
  rep(i,n+1){
    if(s[i]=='?'){
      dp[0][i+1]=dp[0][i]*3;
    }else{
      dp[0][i+1]=dp[0][i];
    }
    dp[0][i+1]%=mod;
  }
  rep(i,n){
    if(s[i]=='A'){
      dp[1][i+1]=dp[1][i]+dp[0][i];
    }else if(s[i]=='?'){
      dp[1][i+1]=3*dp[1][i]+dp[0][i];
    }else{
      dp[1][i+1]=dp[1][i];
    }
    dp[1][i+1]%=mod;
  }
  rep(i,n){
    if(s[i]=='B'){
      dp[2][i+1]=dp[2][i]+dp[1][i];
    }else if(s[i]=='?'){
      dp[2][i+1]=3*dp[2][i]+dp[1][i];
    }else{
      dp[2][i+1]=dp[2][i];
    }
    dp[2][i+1]%=mod;
  }
  rep(i,n){
    if(s[i]=='C'){
      dp[3][i+1]=dp[3][i]+dp[2][i];
    }else if(s[i]=='?'){
      dp[3][i+1]=3*dp[3][i]+dp[2][i];
    }else{
      dp[3][i+1]=dp[3][i];
    }
    dp[3][i+1]%=mod;
  }
  rep(i,4){
    rep2(j,n){
      cerr<<dp[i][j]<<' ';
    }
    cerr<<endl;
  }
  cout<<dp[3][n]<<endl;
  return 0;
}