#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, ans=0;
  cin >> n;
  int d[n];

  rep(i, n)
  {
    cin >> d[i];
  }
  sort(d, d+n);

  int pre = 0;
  rep(i, n)
  {
    if(pre == d[i])
      continue;
    ans++;
    pre = d[i];
  }

  cout << ans << endl;
}
