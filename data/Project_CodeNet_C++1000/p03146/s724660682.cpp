#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int f(int x) {
  if (x%2 == 0) return x/2;
  else return 3*x + 1;
}

int main() {
  int s,ans;
  cin >> s;
  vector<int> a(1000005);
  vector<int> dp(1000005);
  a[1] = s;
  dp[s]++;

  for (int i = 2; i < 1000005; i++) {
    a[i] = f(a[i-1]);
    if (dp[a[i]] != 0) {
      ans = i;
      break;
    }
    else dp[a[i]]++;
  }

  cout << ans << endl;

  return 0;
}