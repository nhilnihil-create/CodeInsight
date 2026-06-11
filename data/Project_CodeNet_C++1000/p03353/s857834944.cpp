#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  set<string> x;
  rep(i,s.size()) rep(j, k+1) {
      string p = s.substr(i,j);
      x.insert(p);
  }
  auto itr = x.begin();
  rep(i,k) itr++;
  cout << *itr << endl;
  return 0;
}