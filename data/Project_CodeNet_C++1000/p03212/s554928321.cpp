#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

vector<ll> cand;

void DFS(ll a) {
  if (a > Mod-7) {
    return ;
  }
  cand.push_back(a*10 + 3);
  cand.push_back(a*10 + 5);
  cand.push_back(a*10 + 7);
  DFS(a*10 + 3);
  DFS(a*10 + 5);
  DFS(a*10 + 7);
  return ;
}

int main() {
  ll N;
  cin >> N;
  DFS(0);
  int ans = 0;
  for (int i = 0; i < (int)cand.size(); i++) {
    if (N >= cand[i]) {
      ll t = cand[i];
      string str = to_string(t);
      bool _3 = false;
      bool _5 = false;
      bool _7 = false;
      for (int j = 0; j < (int)str.size(); j++) {
        if (str[j] == '3') {
          _3 = true;
        } else if (str[j] == '5') {
          _5 = true;
        } else {
          _7 = true;
        }
      }
      if (_3 && _5 && _7) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}