#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;
constexpr ll INF = (1LL << 60);
int main(){ 
  int n;
  ll z, w;
  cin >> n >> z >> w;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll res = abs(w - a[n - 1]);
  if (n > 1) res = max(res, abs(a[n - 2] - a[n - 1]));
  cout << res << endl;
  return 0;
} 
