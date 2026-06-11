#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;} else return false;}
int tb[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
  int n, m; cin >> n >> m;
  vector<int> dp(11000, -INT_MAX);
  vector<int> A(m);
  for(int i = 0; i < m; i++){
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    int k = -INT_MAX;
    for(int j = 0; j < m; j++){
      if(i - tb[A[j]] < 0) continue;
      else if(i - tb[A[j]] > 0){
        chmax(k, dp[i-tb[A[j]]]+1);
      }
      else if(i - tb[A[j]] == 0) k = 1;
    }
  	dp[i] = k;
  } 
  while(n > 0){
    for(int i = 0; i < m; i++){
      if(n - tb[A[i]] < 0) continue;
      if(dp[n - tb[A[i]]] == dp[n] - 1){
        cout << A[i];
        n -= tb[A[i]];
        break;
      }
    }
  }
}