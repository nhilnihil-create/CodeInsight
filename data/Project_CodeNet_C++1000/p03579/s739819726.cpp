#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;


#define MAX_N 100010
#define MAX_M 100010
int n, m;
vector<int> G[MAX_N];
int color[MAX_N];

bool dfs(int v, int c) {
  color[v] = c;
  for(int i = 0; i < G[v].size(); ++i) {
    if(color[G[v][i]] == c) return false;
    if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
  }
  return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

  cin >> n >> m;
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }
  rep(i, 0, n) {
    if(color[i] == 0) {
      if(!dfs(i, 1)) {
        cout << 1ll * n * (n - 1) / 2 - m << endl;
        return 0;
      }
    }
  }
  int b = 0, w = 0;
  rep(i, 0, n) {
    if(color[i] == 1) ++b;
    else ++w;
  }

  cout << 1ll * b * w - m << endl;
}
