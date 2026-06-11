#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  string vac = "Vacant";
  string left, right;
  int n;
  cin >> n; 
  int l = 0, r = n / 2;
  cout << l << endl;
  cin >> left;
  if (left == vac) return 0;
  cout << r << endl;
  cin >> right;
  if (right == vac) return 0;

  auto ok = [&](string mid, int m) {
    if (left == mid) return (m - l) % 2 == 1;
    else return (m - l) % 2 == 0;
  };

  if (!ok(right, r)) {
    swap(left, right);
    l = r;
    r = n;
  }

  while (r - l > 1) {
    string mid;
    int m = (r + l) / 2;
    cout << m << endl;
    cin >> mid;
    if (mid == vac) break;
    if (ok(mid, m)) right = mid, r = m;
    else left = mid, l = m;
  }
  return 0;
} 