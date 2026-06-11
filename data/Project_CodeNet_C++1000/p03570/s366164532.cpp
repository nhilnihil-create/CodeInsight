#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;

//

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

#define DSIZE 1024*1024*64

int dp[DSIZE];
int dp_val[200001];
string s;
int s_acm[200001];

int main(){
  cin >> s;
  
  REP(i,DSIZE){
    dp[i]=500000;
  }
  dp[0]=0;
  
  s_acm[0]=0;
  REP(i,s.size())
    s_acm[i+1]=s_acm[i] ^ (1<<(int)(s[i]-'a'));

  dp_val[0]=0;
  REP(i,s.size()){
    dp_val[i+1] = dp[s_acm[i+1]]+1;
    REP(j,26)
      dp_val[i+1] = min(dp_val[i+1],dp[s_acm[i+1]^(1<<j)]+1);
    dp[s_acm[i+1]] = min(dp[s_acm[i+1]],dp_val[i+1]);
  }
  cout << dp_val[s.size()] << endl;
  return 0;
}
