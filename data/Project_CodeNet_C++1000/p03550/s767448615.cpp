#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n, z, w; cin >> n >> z >> w;
  vi arr(n);
  rep(i,n) cin >> arr[i];

  if (n == 1) cout << abs(arr[0] - w) << endl;
  else cout << max(abs(arr[n-1] - arr[n-2]), abs(arr[n-1] - w)) << endl;
  return 0;
}
