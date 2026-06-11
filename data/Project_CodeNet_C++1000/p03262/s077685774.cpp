#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define REPD(i,a,b) for (int i=(a);i<(b);i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef queue<int> qi;
typedef queue<pi> qpi;
typedef pair<ll, ll> pll;
typedef queue<pll> qpll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const int mod = 1000000007;
const int INF = 1001001001;
// 小数点　<< fixed << setprecision(0) <<
// sort降順　sort(ALL(),greater<int>());
// 円周率　M_PI
// 文字判定　isupper islower
// 順列　do {} while(next_permutation(ALL(X)));
// 最大値　LLONG_MAX
// a内でx以上　auto iter = lower_bound(ALL(a), x);
// a内でxより大きい　auto iter = upper_bound(ALL(a), x);
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};
typedef struct edge se;
typedef vector<edge> ve;
unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
  int n,x;
  cin >> n >> x;
  vi po(n);
  REP(i,n) {
    int p;
    cin >> p;
    po[i]=abs(p-x);
  }
  int ans=po[0];
  REP(i,n-1) {
    ans=euclidean_gcd(ans,po[i+1]);
  }
  cout << ans << endl;
  return 0;
}
