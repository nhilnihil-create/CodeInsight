#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main() {
  int n,m;
  cin >> n >> m;
  int maxL = 1, minR = n;
  rep(i,m) {
    int l,r;
    cin >> l >> r;
    maxL = max(maxL, l);
    minR = min(minR, r);
  }
  int ans = minR + 1 - maxL;
  ans = max(ans,0);
  cout << ans << endl;
}
