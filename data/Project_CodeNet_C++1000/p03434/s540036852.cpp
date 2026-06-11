#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int res = 0;
  rep(i,n) {
    if (i % 2 == 0) res += a[i];
    else res -= a[i];
  }
  cout << res << endl;
  return 0; 
}
