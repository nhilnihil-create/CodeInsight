#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
long long int x[100001];
long long int v[100001];
long long int N,C;

int main()
{
  long long int m=-1,ind,lroad[100001],rroad[100001],left[100001],right[100001];
  cin >> N >> C;
  for(int i=0;i<N;i++)cin >> x[i] >> v[i];
  REP(i,N){
    if(i != 0)
      left[i] = left[i-1] + v[i] - abs(x[i] - x[i-1]);
    else
      left[i] = v[i] - x[i];
    m = max(left[i],m);
  }
  for(int i=N-1;i>=0;i--){
    if(i != N-1){
      right[i] = right[i+1] + v[i] - abs(x[i] - x[i+1]);
    }else{
      right[i] = v[i] - abs(C-x[i]);
    }
    m = max(right[i],m);
  }
  
  REP(i,N){ 
      lroad[i] = x[i];
      rroad[i] = (C - x[i]);
      
  }

  
  long long int dp[100001],dp2[100001],dp3[100001];
  if(N >= 2){
    dp[N-2] = right[N-1];
    dp2[N-2] = rroad[N-1];
    dp3[N-2] = dp[N-2] - dp2[N-2];
  }
  for(int i=N-3;i>=0;i--){
    dp[i] = max(right[i+1],dp[i+1]);
    if(dp[i] != dp[i+1])
      dp2[i] = rroad[i+1];
    else
      dp2[i] = dp2[i+1];
    dp3[i] = max(dp[i] - dp2[i],dp3[i+1]);
  }
  REP(i,N-1){
      m = max(left[i] - lroad[i] + dp[i],m);
      m = max(left[i] + dp3[i] ,m);
  }
  m = max(m,(long long int)0);
  cout << m << endl;
  return 0;
  
}
