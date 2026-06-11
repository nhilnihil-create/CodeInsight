#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, m ,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  int cnt = 0;
  rep(i, n) {
    int sum = 0;
    rep(j, m) {
      int a;
      cin >> a;
      sum += b[j]*a;
      if(j == m-1) {
        if(sum + c > 0) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}