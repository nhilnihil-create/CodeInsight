#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }
  vector<ll> su(n+1, 0);
  for(int i=0;i<n;++i) {
    su[i+1] = su[i] + a[i];
  }
  int l = 1;
  vector<int> fl(n+1);
  for(int i=2;i<=n-2;++i) {
    while(l < i-1 && abs(2*su[l] - su[i]) > abs(2*su[l+1] - su[i])) {
      l++;
    }
    fl[i] = l;
  }
  int r = n-1;
  vector<ll> fr(n+1);
  for(int i=n-2;i>=2;--i) {
    while(r > i+1 && abs(2*su[r] - su[i] - su[n]) > abs(2*su[r-1] - su[i] - su[n])) {
      r--;
    }
    fr[i] = r;
  }
  ll mi = LINF;
  for(int i=2;i<=n-2;++i) {
    ll tmpma = max(su[fl[i]], max(su[i] - su[fl[i]], max(su[fr[i]] - su[i], su[n] - su[fr[i]])));
    ll tmpmi = min(su[fl[i]], min(su[i] - su[fl[i]], min(su[fr[i]] - su[i], su[n] - su[fr[i]])));
    mi = min(mi, tmpma - tmpmi);
  }
  cout << mi << endl;
}
