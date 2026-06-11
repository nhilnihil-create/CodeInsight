#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll r, g, b, n; cin >> r >> g >> b >> n;
  ll ans = 0;
  Rep(i, 0, 3000){
    Rep(j, 0, 3000){
      ll m = n - r*i - g*j;
      if(m < 0) continue;
      if(m%b == 0) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
