#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  int c = 1;
  rep(i,n) {
    cin >> a[i];
    if (a[i] % 2 == 0) c *= 2;
  }
  cout << pow(3,n) - c << endl;;
  return 0;
}