#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<P> ans;
  int minus = n;
  if(n % 2 == 1) --minus;

  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      if(j == minus) continue;
      ans.push_back({i,j});
    }
    --minus;
  }

  cout << ans.size() << endl;
  for(auto a : ans) {
    cout << a.first << " " << a.second << endl;
  }
}
