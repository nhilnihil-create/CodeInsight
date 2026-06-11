#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e15 + 7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main() {
  string s;
  cin >> s;

  int c = 0;
  rep(i,s.size()) if(s[i] == 'B') c++;

  ll ans = 0;
  rep(i,s.size()){
      if(s[i] == 'B') {
        ans += (s.size() - c) - i;
        c--;
      }
  }
  cout << ans << endl;

  return 0;
}
