#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
typedef tuple<int,int,int> TP;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  int res = 0;
  rep(i,n) {
    int a;
    cin >> a;
    mp[a]++;
  }
  for (auto e : mp) {
    if (e.first < e.second) res += abs(e.first - e.second);
    if (e.first > e.second) res += e.second;
  }
  cout << res << endl;
  return 0;
} 