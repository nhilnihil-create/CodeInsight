#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, sum = 0;
double memo[40005] = {0};
int t[105] = {0};
int v[105] = {0};
int bf[105] = {0};
int af[105] = {0};
double now = 0, ans = 0;
vector<pair<int, pair<int, int>>> data;

int main() {
  cout << fixed << setprecision(10);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> t[i];
  for(int i = 0; i < n; ++i) cin >> v[i];
  for(int i = 0; i < n; ++i) {
    bf[i] = sum;
    sum += t[i];
    af[i] = sum;
    memo[(int)now * 2] =
        min(memo[(int)(now * 2)], (double)v[i]);
    while(now < sum) {
      now += 0.5;
      memo[(int)(now * 2)] = (double)v[i];
    }
  }
  memo[sum * 2] = 0;
  for(int i = 0; i < n; ++i)
    data.push_back(
        make_pair(v[i], make_pair(bf[i], af[i])));
  data.push_back(make_pair(0, make_pair(sum, 0)));
  sort(data.begin(), data.end());
  for(int i = 0; i <= n; ++i) {
    double nv = data[i].fi;
    now = data[i].se.fi;
    while(now > 0) {
      now -= 0.5;
      nv += 0.5;
      if(nv < memo[(int)(now * 2)])
        memo[(int)(now * 2)] = nv;
      else
        break;
    }
    nv = data[i].fi;
    now = data[i].se.se;
    while(now < sum) {
      now += 0.5;
      nv += 0.5;
      if(nv < memo[(int)(now * 2)])
        memo[(int)(now * 2)] = nv;
      else
        break;
    }
  }
  for(int i = 1; i <= sum * 2; ++i)
    ans += (memo[i] + memo[i - 1]) * 0.25;
  cout << ans << endl;
  return 0;
}