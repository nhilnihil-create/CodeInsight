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
  vector<ll> v(n+1);
  v[0] = 2;
  v[1] = 1;
  rep(i,n+1-2) {
    v[i + 2] = v[i] + v[i + 1];
  }
  cout << v[n] << endl;
}

int main() {
  solve();
  return 0;
}