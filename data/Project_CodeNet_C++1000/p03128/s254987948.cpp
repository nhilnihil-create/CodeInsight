#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

using Graph = vector<vector<ll>>;
//	std::cout<<std::fixed<<std::setprecision(10);

int main() {
  int N, M;
  cin >> N >> M;
  const int cost[9] = {2,5,5,4,5,6,3,7,6};
  vector<int> A(M);
  rep(i, M) cin >> A[i];
  sort(A.begin(), A.end());

  int dp[N+1]; // dp[i] ... i本のマッチをちょうど使って作れる最大の桁数。
  dp[0] = 0;

  for(int i=1; i<N+1; i++) {
    int tmp_dp = -1000000000;

    rep(j, M) {
      int pre = i - cost[A[j]-1];
      if(pre<0) continue;
      else tmp_dp = max(dp[pre]+1, tmp_dp);
    }

    dp[i] = tmp_dp;
  }

  //cout << dp[N] << endl;

  int n = N;
  for(int i=dp[N]; i>0; i--) {
    // 第n桁目
    for(int j=M-1; j>=0; j--) {
      if(n-cost[A[j]-1]<0) continue; 
      
      if(dp[n-cost[A[j]-1]] == dp[n]-1) {
        cout << A[j];
        n -= cost[A[j]-1];
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
