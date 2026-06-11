#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 100000;
const int MAX_M = 200000;
struct edge{int to, cost;};

vector<edge> G[MAX_N];
int V[MAX_N];

int n, m;
int l[MAX_M], r[MAX_M], d[MAX_M];

bool used[MAX_N];

bool dfs(int v) {
  if(used[v]) return true;
  used[v] = true;
  bool res = true;
  REP(i, G[v].size()){
    if(used[G[v][i].to]) res = res & (G[v][i].cost == V[v] - V[G[v][i].to]);
    else {
      V[G[v][i].to] = V[v] - G[v][i].cost;
      res = res & dfs(G[v][i].to);
    }
  }
  return res;
}

int main(){
  cin >> n >> m;
  REP(i, m) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--; r[i]--;
    G[l[i]].push_back(edge{r[i], d[i]});
    G[r[i]].push_back(edge{l[i], -d[i]});
  }

  REP(i, n) used[i] = false;

  bool ans = true;
  REP(i, n) {
    if(!used[i]) V[i] = 0;
    ans = ans & dfs(i);
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
