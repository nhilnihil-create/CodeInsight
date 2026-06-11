#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;
int n;

int count(vector<int>& b, int l, int r) {
  if (b.empty()) return 0;
  auto hi = lower_bound(b.begin(), b.end(), r);
  if (hi == b.begin()) return 0;
  --hi;
  auto lo = lower_bound(b.begin(), b.end(), l);
  return hi - lo + 1;
}

int solve(int i, vector<int> a, vector<int> b) {
  int mod = 1 << (i+1);
  for (int i=0; i<n; i++) {
    a[i] %= mod;
  }
  for (int i=0; i<n; i++) {
    b[i] %= mod;
  }
  int T = 1 << i;
  sort(b.begin(), b.end());
  int res = 0;
  for (int x: a) {
    int cnt = 0;
    cnt += count(b, T-x, 2*T-x);
    cnt += count(b, 3*T-x, 4*T-x);
    res += cnt;
  }
  return res;  
}

vector<int> a, b;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n;
  a.resize(n);
  b.resize(n);
  for (int i=0; i<n; i++) {
    cin>>a[i];
  }
  for (int i=0; i<n; i++) {
    cin>>b[i];
  }

  int ans = 0;

  for (int j=28; j>=0; j--) {
    int res = solve(j, a, b);
    //cout<<j<<": "<<res<<endl;
    if (res%2) {
      ans = ans | (1 << j);
    }
  }

  cout<<ans<<endl;
  return 0;
}
// don't forget to read in the input :^)
