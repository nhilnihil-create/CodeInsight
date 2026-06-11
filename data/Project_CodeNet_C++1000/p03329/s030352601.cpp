#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int dp[100010];
  dp[0] = 0;
  for(int i=1; i<100005; i++){
    dp[i] = 1000000;
    int f=1;
    while(f<=i){
      dp[i] = min(dp[i-f]+1, dp[i]);
      f *= 6;
    }
    f=1;
    while(f<=i){
      dp[i] = min(dp[i-f]+1, dp[i]);
      f *= 9;
    }
  }
  int n;
  cin >> n;
  cout << dp[n] << endl;
  return 0;
}
