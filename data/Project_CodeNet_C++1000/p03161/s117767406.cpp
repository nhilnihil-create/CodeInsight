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
  int n, k;
  cin >> n >> k;
  vec<int> h(n+1);
  rep(i, n) cin >> h[i+1];

  int dp[n+1];
  rep(i, n+1){
    dp[i] = 0;
  }
  dp[1] = 0;
  
  repab(i, 2, n){
    dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
    for(int j=2; j<=k; j++){
      if(i-j>=1) dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }
  }

  cout << dp[n] << endl;

  return 0;
}