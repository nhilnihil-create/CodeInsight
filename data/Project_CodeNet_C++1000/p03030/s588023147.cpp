#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> vec(n);
  rep(i, n) {
    string s;
    int x = i + 1, p;
    cin >> s >> p;
    tuple<string, int, int> tpl(s, -1 * p, x);
    vec.at(i) = tpl;
  }
  sort(vec.begin(), vec.end());
  for (tuple tpl : vec) {
    int a = get<2>(tpl);
    cout << a << endl;
  }    
}