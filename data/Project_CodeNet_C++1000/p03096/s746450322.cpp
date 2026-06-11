#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

signed main(){
  int n;
  cin >> n;

  vi c(n);
  rep(i, 0, n) cin >> c[i];

  vi places[200001];
  vi dp(200001);

  rep(i, 0, n) places[c[i]].emplace_back(i);

  dp[0] = 1;
  rep(i, 1, n+1){
    (dp[i] += dp[i-1]) %= mod;

    int color = c[i-1];
    int it = lower_bound(all(places[color]), i-1) - places[color].begin();
    if(it > 0){
      int j = places[color][it-1];
      if((i-1) - j > 1) (dp[i] += dp[j+1]) %= mod;
    }
  }

  cout << dp[n] << endl;

  return 0;
}
