#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;

#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define absd(x) (x<0?-(x):x)
#define pow2(x) ((x)*(x))
#define rep(i,n) for(int i=0; i<n; ++i)
#define repr(i,n) for(int i=n-1; i>=0; --i)
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define replr(i,s,n) for(int i=n; i>=s; --i)
#define repf(i,s,n,j) for(int i=s; i<=n; i+=j)
#define repe(e,obj) for(auto e : obj)

#define SP << " " <<
#define COL << " : " <<
#define COM << ", " <<
#define ARR << " -> " <<
#define PNT(STR) cout << STR << endl
#define POS(X,Y) "(" << X << ", " << Y << ")"
#define DEB(A) " (" << #A << ") " << A
#define DEBREP(i,n,val) for(int i=0; i<n; ++i) cout << val << " "; cout << endl
#define ALL(V) (V).begin(), (V).end()
#define INF 1000000007
#define INFLL 1000000000000000007LL
#define EPS 1e-9

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define P_TYPE int
typedef pair<P_TYPE, P_TYPE> P;
typedef pair<P, P_TYPE> PI;
typedef pair<P_TYPE, P> IP;
typedef pair<P, P> PP;
typedef priority_queue<P, vector<P>, greater<P> > pvqueue;

#define N 200003

int n, m, lb;
int used[N][4];
int t[4] = {'A', 'A', 'B', 'B'};
string s;

vector<int> g[N];

int dfs(int v, int k) {
  if(used[v][k]) {
    return used[v][k] == lb;
  }
  used[v][k] = lb;
  int k1 = (k + 1) % 4;
  repe(w, g[v]) {
    if(s[w] == t[k1] && dfs(w, k1)) {
      return 1;
    }
  }
  used[v][k] = -1;
  return 0;
}

int main() {
  cin >> n >> m >> s;
  rep(i, m) {
    int a, b; cin >> a >> b; --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bool ok = false;
  rep(i, n) {
    lb = i+1;
    if(s[i] == 'A' ? dfs(i, 0) : dfs(i, 2)) {
      ok = true;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}