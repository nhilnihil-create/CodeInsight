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
  vector<pair<int, vector<int>>> v(m);
  vector<int> p(m);
  rep(i,m) {
    int k;
    cin >> k;
    v[i].first = k;
    rep(j,k) {
      int s;
      cin >> s;
      v[i].second.push_back(s- 1);
    }
  }
  rep(i,m) cin >> p[i];

  int ans = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    bool isOk = true;
    rep(i, m) {
      int count = 0;
      int k = v[i].first;
      auto s = v[i].second;
      rep(j,k) {
        if (bit & (1 << s[j])) count++;
      }
      if (count % 2 != p[i]) isOk = false;
    }
    if (isOk) ans++;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}