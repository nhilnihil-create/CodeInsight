#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());

  if(s < t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}