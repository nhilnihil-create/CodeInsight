#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> r;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    r.push_back(make_tuple(s, -x, i + 1));
  }
  sort(all(r));
  for (int i = 0; i < n; i++) {
    cout << get<2>(r[i]) << endl;
  }
  return 0;
}