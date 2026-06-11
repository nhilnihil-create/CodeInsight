#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, H;
  cin >> N >> H;
  vector<pair<int, int>> katana;
  int maxA = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > maxA) {
      maxA = a;
    }
    katana.emplace_back(b, a);
  }
  sort(katana.begin(), katana.end());
  reverse(katana.begin(), katana.end());
  int ans = 0;
  for (auto x : katana) {
    if(H <= 0){
      cout << ans <<endl;
      return 0;
    }
    int b = x.first;
    if (b <= maxA) {
      break;
    }
    H -= b;
    ans++;
  }
  ans += ceil((long double)H / maxA);
  cout << ans << endl;
}