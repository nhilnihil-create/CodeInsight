#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int64_t d, g;
  cin >> d >> g;
  vi p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i]; 

  int ans = 10000;
  rep(tmp, 1<<d) {
    bitset<10> bit(tmp);
    int64_t sum = 0;
    int curr = 0;
    int rest_max = 0;
    rep(i, d) {
      if (bit[i] == 0) rest_max = i;
      else {
        sum += 100*(i+1)*p[i] + c[i];
        curr += p[i];
      }
    }
    if (sum < g) {
      int curr_rest = ((g-sum)/100+rest_max)/(rest_max+1);
      if (curr_rest <= p[rest_max]) curr += curr_rest;
      else continue;
    }
    ans = min(ans, curr);
  }
  cout << ans << endl;
}
