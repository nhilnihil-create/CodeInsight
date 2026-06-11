#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define ld long double
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define mod 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N, M, D; cin >> N >> M >> D;
  ld ans;
  if (D == 0) {
    ans = (ld)(M - 1) / N;
  } else {
    ans = (ld)(M - 1) * (N - D) * 2 / (N * N);
  }
  cout << fixed << setprecision(10) << ans << endl;
}