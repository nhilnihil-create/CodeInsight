#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n,m) for(int i=m; i<n; i++)
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << x << endl;
#define END cout << endl;
#define sorti(x) sort(x.begin(), x.end())

const int MAX = 100010;
vector<pair<int, int> > edge[MAX];
int visited[MAX];
int d[MAX];

void dfs(int next, int cost) {
  visited[next] = true;
  d[next] = cost;
  for (auto to : edge[next]) {
    if (!visited[to.first]) dfs(to.first, cost + to.second);
    else {
      if (d[to.first] != cost + to.second) {
        cout << "No" << endl;
        exit(0);
      }
    }
  }
}

int main() {
  int n,m; cin >> n >> m;
  rep(i,m) {
    ll l,r,d; cin >> l >> r >> d;
    edge[l].pb({r,d});
    edge[r].pb({l,-d});
  }
  repr(i,n+1,1) {
    if(!visited[i]) dfs(i,0);
  }
  cout << "Yes" << endl;
}