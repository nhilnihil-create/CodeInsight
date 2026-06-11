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
  vector<string> v(n);
  rep(i,n) cin >> v[i];
  map<string, int> mp;
  char prev = v[0][0];
  rep(i,n) {
    if (mp[v[i]] || prev != v[i][0]) {
      cout << "No" << endl;
      return;
    }
    prev = v[i][v[i].size()-1];
    mp[v[i]]++;
  }
  cout << "Yes" << endl;
}

int main() {
  solve();
  return 0;
}