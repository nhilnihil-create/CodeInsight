#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, int> PL;
constexpr ll INF = (1LL << 60);

int main() {
  int n;
  cin >> n;
  map<int,int> mp1, mp2;
  rep(i,n) {
    int d;
    cin >> d;
    mp1[d]++;
  }
  int m;
  cin >> m;
  rep(i,m) {
    int t;
    cin >> t;
    mp2[t]++;
  }
  bool ok = true;
  for (auto e : mp2) {
    if (mp1[e.first] < e.second) ok = false;
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
} 