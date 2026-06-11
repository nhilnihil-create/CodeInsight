#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
  fastIO;
  int n;
  cin >> n;

  vector<pair<pair<string, int>, int>> city;

  rep(i, n) {
    string s;
    cin >> s;
    int p;
    cin >> p;
    // -point for desc scores
    city.push_back(make_pair(make_pair(s, -p), i));
  }

  sort(city.begin(), city.end());

  for(auto pair: city) {
    cout << pair.second + 1 << endl;
  }
}
