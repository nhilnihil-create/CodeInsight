#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll C;
  cin >> C;
  ll x[N],v[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> v[i];
  }
  ll right_mx[N];
  ll left_mx[N];
  ll right_mx_2[N];
  ll left_mx_2[N];
  ll now = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      now -= x[i];
    } else {
      now -= x[i] - x[i-1];
    }
    now += v[i];
    if (i == 0) {
      right_mx[i] = max(0LL,now - x[i]);
      right_mx_2[i] = max(0LL,now);
    } else {
      right_mx[i] = max(right_mx[i-1],now - x[i]);
      right_mx_2[i] = max(right_mx_2[i-1],now);
    }
  }
  now = 0;
  for (int i = N-1; i >= 0; i--) {
    if (i == N-1) {
      now -= (C - x[i]);
    } else {
      now -= x[i+1] - x[i];
    }
    now += v[i];
    if (i == N-1) {
      left_mx[i] = max(0LL,now - (C - x[i]));
      left_mx_2[i] = max(0LL,now);
    } else {
      left_mx[i] = max(left_mx[i+1],now - (C - x[i]));
      left_mx_2[i] = max(left_mx_2[i+1],now);
    }
  }
  ll ans = 0;
  ans = max(ans,left_mx_2[0]);
  ans = max(ans,right_mx_2[N-1]);
  for (int i = 0; i < N-1; i++) {
    ll res1 = right_mx_2[i] + left_mx[i+1];
    ll res2 = right_mx[i] + left_mx_2[i+1];
    ans = max({ans,res1,res2});
  }
  cout << ans << endl;
  return 0;
}