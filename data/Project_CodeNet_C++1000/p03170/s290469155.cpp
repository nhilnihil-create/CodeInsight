#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, k;
  cin >> n >> k;
  vi a(n+1);
  rep(i,n) cin >> a[i+1];
  vi dp(k+1);
  for(int i=1; i<=k; i++){
    for(int j=1; j<=n; j++){
      if(i-a[j] >= 0 && dp[i-a[j]] == 0) dp[i] = 1;
    }
  }
  if(dp[k] == 1) cout << "First" << endl;
  else cout << "Second" << endl;
}
