#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  map<string, vector<P>> mp;
  rep(i, N) {
    string S;
    int P;
    cin >> S >> P;
    mp[S].emplace_back(P, i);    
  }
  for (auto p : mp) {
    sort(p.second.rbegin(), p.second.rend());
    for (auto p2 : p.second) {
      cout << p2.second + 1 << '\n';
    }
  }
  return 0;
}