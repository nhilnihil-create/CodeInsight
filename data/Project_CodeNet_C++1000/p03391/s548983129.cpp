#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector<ll> a(n), b(n);
  ll su = 0;
  ll mi = INF;
  for(int i=0;i<n;++i) {
    cin >> a[i] >> b[i];
    su += a[i];
    if(a[i] > b[i]) mi = min(mi, b[i]);
  }
  cout << (a == b ? 0 : su - mi) << endl;
}
