#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s; cin >> s;
  int l = s.size();
  bool ok = false;
  string k = "keyence";
  for (int i = 0; i <= 7; i++)
  {
    string t = s.substr(0,i) + s.substr(l-(7-i),7-i);
    
    if (t == k) ok = true;
  }
  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}