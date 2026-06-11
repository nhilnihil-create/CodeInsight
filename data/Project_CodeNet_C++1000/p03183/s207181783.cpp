#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct Plate{
  int w, s, v;
  Plate(){}
  Plate(int _w, int _s, int _v){
    w = _w;
    s = _s;
    v = _v;

  }
} ps[1001];
int n;
ll dp[1001][10001];
ll solve(int in, int can){
  if(can < 0)
    return -1e9;
  if(in == n)
    return 0;
  if(dp[in][can] != -1)
    return dp[in][can];
  return dp[in][can] = max(solve(in + 1, can), ps[in + 1].v + solve(in + 1, min(can - ps[in + 1].w, ps[in + 1].s)));
}
int main()
{
//  freopen("lcm.in", "r", stdin);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//  cout << 300 << endl;
//  for(int i = 0;i < 300;i++){
//    cout << rand() % 10000 + 1 << ' ' << rand() % 10000 + 1 << ' ' << rand() % 1000000000 + 1 << endl;
//  }
//  return 0;
  cin >> n;
  for(int i = 0;i < n;i++)
    cin >> ps[i].w >> ps[i].s >> ps[i].v;
  sort(ps, ps + n, [](const Plate& a, const Plate& b){
    return min(a.s, b.s - a.w) < min(b.s, a.s - b.w);
  });
  memset(dp, -1, sizeof(dp));

  ll res = 0;
  for(int i = 0;i < n;i++)
    res = max(res, ps[i].v + solve(i, ps[i].s));
  cout << res;
  return 0;
}
