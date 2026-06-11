#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;
 
int main(){ 
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> dp(k + 1, 0);

  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0) dp[i] |= dp[i - a[j]] ^ 1;
    }
  }
  if (dp[k]) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
} 
