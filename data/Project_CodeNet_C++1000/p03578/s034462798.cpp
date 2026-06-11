#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  map<int,int> d;
  rep(i,n) {
    int dd; cin >> dd;
    d[dd]++;
  }
  int m;
  cin >> m;
  bool can = true;
  rep(i,m) {
    int t; cin >> t;
    if (d[t] > 0) d[t]--;
    else {can = false;}
  }
  if (can) cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}