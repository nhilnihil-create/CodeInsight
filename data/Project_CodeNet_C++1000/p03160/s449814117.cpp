#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//------------------------------------------------------//

int main(){
  int n;
  cin >> n;
  vec<int> h(n);
  rep(i, n) cin >> h[i]; 

  int dp[n];
  rep(i, n){
    dp[i] = 0;
  }
  dp[0] = 0; 
  dp[1] = abs(h[0]-h[1]);
  
  rep(i, n-2){
    dp[i+2] += min(dp[i+1]+abs(h[i+1]-h[i+2]), dp[i]+abs(h[i]-h[i+2]));
  }

  cout << dp[n-1] << endl;

  return 0;
}