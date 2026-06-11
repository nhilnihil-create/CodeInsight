#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

vector<int> G[100100], H[100100];
int N, M;
bool used[100100] = {false};
vector<int> topo;

void dfs(int s) {
  if(used[s] == true) return;
  used[s] = true;
  for(int i = 0; i < G[s].size(); i++) dfs(G[s][i]);
  topo.push_back(s);
}

void tpsort() {
    rep1(i, N) dfs(i);
    reverse(topo.begin(), topo.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  rep(i, N + M - 1) {
      int s, t; cin >> s >> t;
      G[s].push_back(t);
      H[t].push_back(s);
  }
  
  tpsort();
  map<int, int> tp;
  rep(i, N) {
      tp[topo[i]] = i;
  }
  rep1(i, N) {
    int k = -1;
    for(int j: H[i]) {
        k = max(k, tp[j]);
    }
    if(k == -1) {
        cout << 0 << "\n";
        continue;
    } else {
        cout << topo[k] << "\n";
    }
  }
  return 0;
}