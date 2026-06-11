#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e16;

#define rep(i, N) for(ll i=0; i<N; ++i)

ll max(ll a, ll b) {return a < b ? b : a; }
ll min(ll a, ll b) {return a > b ? b : a; }
double maxf(double a, double b) { return a < b ? b : a; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans = 0;
  for(int i = 1; i < n; i++){
    if(a[i-1] == a[i]) {
      ans++;
      a[i] = -1;
    }
  }
  cout<<ans<<endl;
  return 0;
}