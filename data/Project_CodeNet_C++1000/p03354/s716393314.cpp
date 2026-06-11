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
class UnionFind {
public:
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}

  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      if(data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
  }
  int size(int x) {
    return -data[find(x)];
  }
};
int n, m;
int p[100000];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  UnionFind uf(n);

  REP(i, n) {
    cin >> p[i];
    p[i]--;
  }

  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }

  int ans = 0;
  REP(i, n) {
    if(p[i] == i || uf.find(p[i]) == uf.find(i)) ans++;
  }

  cout << ans << endl;
}
