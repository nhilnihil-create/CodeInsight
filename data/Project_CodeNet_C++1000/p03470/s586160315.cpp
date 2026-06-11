#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    cin >> d;
    mp[d]++;
  }
  cout << mp.size() << endl;
  return 0;
}
