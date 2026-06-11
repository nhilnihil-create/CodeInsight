#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;

  for(int i=0; i < n; i++) {
    int cnt = 0;
    for(int j=i; j < n; j++) {
      char c = s[j];
      if (c == 'A' || c == 'C' || c == 'G' || c == 'T') cnt++;
      else break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}