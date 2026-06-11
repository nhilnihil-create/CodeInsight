#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> gate(n+1,0);
  rep(i,0,m) {
    int l,r;
    cin >> l >> r;
    gate[l-1]++; gate[r]--;
  }
  rep(i,1,n+1) {
    gate[i] += gate[i-1];
  }
  int ans = 0;
  rep(i,0,n) {
    if (gate[i] == m) ans++;
  }
  cout << ans << endl;
  return 0;
}
