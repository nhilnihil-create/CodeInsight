#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  map<int, int> d;
  rep(i,n) {
    int a;
    cin >> a;
    d[a]++;
  }
  int m;
  cin >> m;
  map<int, int> t;
  rep(i,m){
    int b;
    cin >> b;
    t[b]++;
  }
  if (n < m) {
    cout << "NO" << endl;
    return;
  }
  for(auto p: t) {
    if (d[p.first] < p.second) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  solve();
  return 0;
}