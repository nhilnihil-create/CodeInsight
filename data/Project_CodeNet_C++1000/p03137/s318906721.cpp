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
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i,m) cin >> x[i];
  sort(ALL(x));
  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,m-1) {
    q.push(abs(x[i] - x[i+1]));
  }
  int ans = 0;
  rep(i,m-1-(n-1)) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}