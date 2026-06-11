#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int mi[(1<<26)];
int dp[200020];

const int INF=1e8;

int main(){
  string s;
  cin>>s;
  int n=s.size();

  vector<int> x;
  x.push_back(0);
  int two=1;
  for(int i=1;i<=26;i++){
      x.push_back(two);
      two*=2;
  }
  
  for(int i=0;i<(1<<26);i++) mi[i]=INF;

  dp[0]=0;
  mi[0]=0;
  int now=0;
  for(int i=0;i<n;i++){
      now=now^(1<<(s[i]-'a'));
      int res=INF;
      for(int j=0;j<x.size();j++){
          int target=now^x[j];
          if(mi[target]==INF) continue;
          res=min(res,mi[target]+1);
      }
      dp[i+1]=res;
      mi[now]=min(mi[now],dp[i+1]);
  }
  cout<<dp[n]<<endl;


  return 0;
}
