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
  ll n, a, b; cin >> n >> a >> b;
  if(a + b > n + 1) {
    cout << -1 << endl;
    return 0;
  }
  if(a*b < n) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> v;
  ll s = n - a;
  ll cur = n;
  for(int i=0;i<a;++i) {
    int num = min(b-1, s) + 1;
    s -= num - 1;
    for(int j=0;j<num;++j) {
      v.push_back(cur - num + 1 + j);
    }
    cur -= num;
  }
  reverse(v.begin(), v.end());
  printv(v);
}
