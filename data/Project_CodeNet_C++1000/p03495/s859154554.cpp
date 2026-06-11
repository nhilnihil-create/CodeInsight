#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n+1);
  rep(i,n) {
    int x; cin >> x;
    a[x]++;
  }
  int cnt = 0;
  sort(a.rbegin(), a.rend());
  rep(i,k) {
    cnt += a[i];
  }
  cout << n - cnt << endl;
  return 0;
}