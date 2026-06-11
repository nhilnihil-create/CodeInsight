#include <iostream>

using namespace std;

const int MAXN = 2e5+10;

int n;
string s;
int white[MAXN], black[MAXN];

void solve() {
  s = 'x' + s + 'x';
  for (int i=0;i<n+1;i++) {
    black[i+1] = black[i] + (s[i] == '#');
  }
  for (int i=n+1;i>0;i--) {
    white[i-1] = white[i] + (s[i] == '.');
  }
  int ans = MAXN;
  for (int i=1;i<=n;i++) {
    ans = min(ans, black[i] + white[i]);
  }
  cout << ans << endl;
}

int main() {
  cin >> n >> s;
  solve();
}
