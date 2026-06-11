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

int n = 101;

int func(int x) {
  if (x == 0) return 0;
  return func(x/10) + x%10; 
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = func(i);
    if (a <= x && x <= b) ans += i;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}