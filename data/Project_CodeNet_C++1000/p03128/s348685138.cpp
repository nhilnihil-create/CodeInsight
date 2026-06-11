#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector < int > cst = {INT_MAX, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector < int > a(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  sort(a.begin() + 1, a.end(), greater < int > ());

  vector < int > dp(n + 1, -1e9);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i - cst[a[j]] >= 0) dp[i] = max(dp[i], 1 + dp[i - cst[a[j]]]);
    }
  }

  while (n > 0) {
    int mx_digits = -1, num = -1;
    for (int j = 1; j <= m; j++) {
      if (n - cst[a[j]] >= 0 && dp[n - cst[a[j]]] > mx_digits) {
        mx_digits = dp[n - cst[a[j]]];
        num = a[j];
      }
    }

    cout << num;
    n -= cst[num];
  }

  cout << '\n';
}
