#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char s[4];
  scanf("%s", s);
  int ans = 0;
  rep(i, 3) if (s[i] == '1') ans++;
  cout << ans << endl;
  return 0;
}