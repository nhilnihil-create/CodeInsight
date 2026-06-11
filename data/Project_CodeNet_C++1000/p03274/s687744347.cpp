#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> x(n);
  rep(i,n) cin >> x[i];
  ll ans = pow(10,15);
  rep(i,n-k+1) {
    int l = i;
    int r = i + k - 1;
    ll temp = 0;
    if (x[l] <= 0 && x[r] <= 0) temp = abs(x[l]);
    else if (x[l] >= 0 && x[r] >= 0) temp = x[r];
    else {
      temp = 2 * min(abs(x[l]), abs(x[r])) + max(abs(x[l]), abs(x[r]));
    }
    ans = min(ans,temp);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}