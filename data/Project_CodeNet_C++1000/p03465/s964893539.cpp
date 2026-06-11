#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vivi;
typedef vector<ll> vll;
typedef vector<vll> vllvll;
typedef pair<int, int> P;
typedef queue<P> QP;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
const int mINF = -1001001001;
const int mod = 1000000007;
// 小数点　<< fixed << setprecision(0) <<
// sort降順　sort(ALL(),greater<int>());
// 文字判定　isupper islower
// 順列　do {} while(next_permutation(ALL(X)));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};
typedef struct edge se;
typedef vector<edge> ve;

int main() {
  int n,sum=0;
  cin >> n;
  vi a(n);
  REP(i,n) {
    cin >>a[i];
    sum+=a[i];
  }
  bitset<4000001> dp;
  dp[0]=1;
  REP(i,n) {
    dp|=(dp<<a[i]);
  }
  for(int i=(sum+1)/2;i<=sum;i++) {
    if(dp[i]==1) {
      cout << i << endl;
      break;
    }
  }


  return 0;
}
