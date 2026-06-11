#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int res = 0;
  rep(i,n) res += a[i];
  cout << res - n << endl;
  return 0; 
} 