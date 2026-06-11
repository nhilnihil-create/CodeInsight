#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  int now = 0, cnt = 1, ans = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if(a == now)
      cnt++;
    else {
      ans += cnt / 2;
      cnt = 1;
    }
    now = a;
  }
  ans += cnt / 2;
  cout << ans << endl;
}