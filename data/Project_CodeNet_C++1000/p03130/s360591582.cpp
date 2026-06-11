#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> cnt(4);
  rep(i, 6) {
    int t;
    cin >> t;
    cnt[t-1]++;
  }
  if (*min_element(cnt.begin(), cnt.end()) == 1 &&
      *max_element(cnt.begin(), cnt.end()) == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}