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
  int s;
  cin >> s;
  int cnt = 1;
  vector<int> x(300);
  x[s] = 1;
  for(;;) {
    cnt++;
    if (s%2==0) s = s/2;
    else s = 3 * s + 1;
    if (x[s]) break;
    else x[s]++;
  }
  cout << cnt << endl;
}

int main() {
  solve();
  return 0;
}