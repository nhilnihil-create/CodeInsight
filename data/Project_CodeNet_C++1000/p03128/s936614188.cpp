//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

#define MAX_N 100000000
#define INF 1000000000

int main(){
  int n,m;
  cin >> n >> m;
  int a[m];
  for(int i=0;i<m;i++) cin >> a[i];
  int ma[10];
  ma[1] = 2;
  ma[2] = 5;
  ma[3] = 5;
  ma[4] = 4;
  ma[5] = 5;
  ma[6] = 6;
  ma[7] = 3;
  ma[8] = 7;
  ma[9] = 6;
  sort(a,a+m);
  int dp[n+1];
  dp[0] = 0;
  for(int i=1;i<n+1;i++){
    dp[i] = -1*INF;
    for(int j=0;j<m;j++){
      if(i-ma[a[j]] >= 0){
        dp[i] = max(dp[i],dp[i-ma[a[j]]]+1);
      }
    }
  }
  string ans = "";
  int count = n;
  for(int i=0;i<dp[n]-1;i++){
    for(int j=m-1;j>=0;j--){
      if(dp[count]-1 == dp[count-ma[a[j]]] && count-ma[a[j]] >= 0){
        count -= ma[a[j]];
        ans += to_string(a[j]);
        break;
      }
    }
  }

  for(int j=m-1;j>=0;j--){
    if(count == ma[a[j]]){
      ans += to_string(a[j]);
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
