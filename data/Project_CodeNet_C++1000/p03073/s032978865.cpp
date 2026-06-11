#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int ans1 = 0, ans2 = 0;
    rep(i,s.size()) {
      if (i%2 == 0 && s[i] == '0') ans1++;
      if (i%2 != 0 && s[i] == '1') ans1++;
    }
    rep(i,s.size()) {
      if (i%2 == 0 && s[i] == '1') ans2++;
      if (i%2 != 0 && s[i] == '0') ans2++;
    }
    int ans = min(ans1, ans2);
    cout << ans << endl;
    return 0;
}