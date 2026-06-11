#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << x << endl;
#define END cout << endl;
#define sorti(x) sort(x.begin(), x.end())

const int N = 100010;
vector<pair<int,int> > v[N];
int d[N];
bool used[N];

void dfs(int x, int y) {
  used[x] = true;
  d[x] = y;
  for (auto to : v[x]) {
    if (!used[to.first]) {
      dfs(to.first, y + to.second);
    } else {
      if (d[to.first] != y + to.second) {
        cout << "No" << endl;
        exit(0);
      }
    }
  }
}

int main() {
  int n,m; cin >> n >> m;
  rep(i,m) {
    int l,r,d;
    cin >> l >> r >> d;
    v[l].pb(make_pair(r,d));
    v[r].pb(make_pair(l,-d));
  }
  repr(i,n+1,1) {
    if (!used[i]) {
      dfs(i,0);
    }
  }

  cout << "Yes" << endl;
}