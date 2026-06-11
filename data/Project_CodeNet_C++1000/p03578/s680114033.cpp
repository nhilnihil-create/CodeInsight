#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;
  map<int, int> mpa, mpb;
  rep(i, n) {
    int a;
    cin >> a;
    mpa[a]++;
  }
  int m;
  cin >> m;
  vector<int> B(m);
  rep(i, m) {
    int b;
    cin >> b;
    B[i] = b;
    mpb[b]++;
  }
  
  bool flag = true;
  rep(i, m) {
    if (mpb[B[i]] > mpa[B[i]]) {
      flag = false;
      break;
    }
  }
  if (flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
