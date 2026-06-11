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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  rep(i,m) cin >> v[i].first >> v[i].second;
  int l = 1;
  int r = n;
  rep(i,m) {
    l = max(l, v[i].first);
    r = min(r, v[i].second);
  }
  cout << max(0, r - l + 1) << endl;
}

int main() {
  solve();
  return 0;
}