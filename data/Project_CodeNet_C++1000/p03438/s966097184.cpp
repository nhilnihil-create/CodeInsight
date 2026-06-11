#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  ll cur = 0;
  //操作回数を考える
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    if (a[i] < b[i]) {
      int d = (b[i] - a[i]) / 2;
      cur += d;
    } else {
      cur -= (a[i] - b[i]);
    }
  }
  if (cur >= 0LL) {
    cout << "Yes" << endl;
  } else cout << "No" << endl;
  return 0;
} 