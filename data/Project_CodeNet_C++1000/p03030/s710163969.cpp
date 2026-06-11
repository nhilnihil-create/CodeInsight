#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> sp;
  rep(i, n)
  {
    string s;
    int p;
    cin >> s >> p;
    sp.push_back(make_tuple(s, -p, i+1));
  }

  sort(sp.begin(), sp.end());

  rep(i, n)
  {
    cout << get<2>(sp.at(i)) << endl;
  }

}
