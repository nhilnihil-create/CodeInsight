#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int N, C;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  vector<priority_queue<P, vector<P>, greater<P>>> ques(C);

  REP(i, N) {
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    ques[c].push(P(s, t));
  }

  vector<int> memo(100005, 0);

  REP(i, C) {
    while(!ques[i].empty()) {
      P p = ques[i].top(); ques[i].pop();
      int s = p.first, e = p.second;

      while(!ques[i].empty()) {
        P np = ques[i].top();
        if(e == np.first) {
          e = np.second;
          ques[i].pop();
        } else {
          break;
        }
      }

      memo[s] += 1; memo[e + 1] -= 1;
    }
  }
  int ans = 0, sum = 0;
  REP(i, 100005) {
    sum += memo[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
}
