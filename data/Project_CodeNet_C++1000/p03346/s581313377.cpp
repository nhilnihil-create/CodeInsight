#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  vector < int > dp(n + 1, 0);
  int mx = 0;
  for(int i = 0; i < n; i++){
    dp[p[i]] = 1 + dp[p[i] - 1];
    mx = max(dp[p[i]], mx);
  }

  cout << n - mx << endl;
}
