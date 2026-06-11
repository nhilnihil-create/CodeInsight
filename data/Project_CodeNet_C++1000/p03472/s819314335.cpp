#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n, h;
  cin >> n >> h;
  vector<ll> a(n);
  vector<ll> b(n);

  rep(i,n) {
    cin >> a[i] >> b[i];
  }

  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());

  ll a_attack = a[0];
  bool is_a = false;

  int cnt = 0;
  int cur_h = 0;
  int cur_b = 0;
  while(cur_h < h) {
    if(!is_a && a_attack < b[cur_b]) {
      cur_h += b[cur_b];
      cur_b++;
      cnt++;
      if(cur_b > n) {
        is_a = true;
      }
    } else {
      is_a = true;
    }

    if(is_a) {
      // 残り
      ll res = h - cur_h;
      ll res_cnt = res / a_attack;
      if(res % a_attack != 0) {
        res_cnt++;
      }
      cnt += res_cnt;
      break;
    }
  }

  cout << cnt << endl;
  return 0;
}
