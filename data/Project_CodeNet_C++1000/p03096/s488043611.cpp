#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1000000007;

int n;
vi c;
set<int> r[200050];

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin);
  cin >> n;
  c.resize(n);
  rep(i,0,n) {
    cin >> c[i];
  }

  ll dp[200050];
  rep(i,0,200050) dp[i] = 0;

  per(i,0,n) {
    r[c[i]].insert(i);
    auto it = r[c[i]].upper_bound(i);
    if(it == r[c[i]].end() || *it == i+1) {
      dp[i] = dp[i+1];
    } else {
      int j = *it;
      dp[i] += dp[j]+1;
      dp[i] += dp[i+1];
      dp[i] %= MOD;
    }
  }

  cout << (dp[0]+1)%MOD << endl;
  return 0;
}