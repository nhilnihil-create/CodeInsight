#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define uset unordered_set
#define umap unordered_map
#define all(x) (x).begin(),(x).end()

int chmin(int &a, int b) { if (a > b) { a = b; return 1; } return 0; }
int chmax(int &a, int b) { if (a < b) { a = b; return 1; } return 0; }

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int s = 1, p = 1;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    s *= 3;
    if (t % 2 == 0) p *= 2;
  }
  cout << s - p << '\n';
}
