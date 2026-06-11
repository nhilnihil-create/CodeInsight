#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int n; cin >> n;
  std::vector<int> v(n);
  std::vector<int> c(n);
  rep(i,n) cin >> v.at(i);
  rep(i,n) cin >> c.at(i);

  int ans = 0;
  rep(i,n) {
    if (v.at(i) > c.at(i)) {
      ans += v.at(i) - c.at(i);
    }
  }
  cout << ans << endl;
}
