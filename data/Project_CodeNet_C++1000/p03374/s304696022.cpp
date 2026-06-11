#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <stack>

typedef long long ll;

const double EPS = 1e-10;
const double PI  = acos(-1);
const ll     INF = LLONG_MAX /10;

ll gcd(ll a, ll b)
{
  while (b > 0) {
    a = a % b;
    std::swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) {
  ll gcd_val = gcd(a, b);
  return a / gcd_val * b;   // over flow 防止のため、割り算を先にする
}

ll extgcd(ll a, ll b, ll& x, ll& y)
{
  ll d = a;
  if (b != 0) {
    ll x_dash;
    ll y_dash;
    d = extgcd(b, a % b, x_dash, y_dash);
    x = y_dash;
    y = x_dash - (a / b) * y_dash;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main(int argc, char* argv[])
{
  ll N, C;
  std::cin >> N >> C;

  std::vector< std::pair< ll, ll > > vp   (N, std::make_pair(0LL, 0LL));
  std::vector< std::pair< ll, ll > > vsum (N+1, std::make_pair(0LL, 0LL));
  std::vector< std::pair< ll, ll > > vrsum(N+1, std::make_pair(0LL, 0LL));
  std::vector< ll >::iterator it;

  for (ll i = 0; i < N; i++) {
    std::cin >> vp[i].first >> vp[i].second;
  }

  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum += vp[i].second;
    vsum[i].first  = vp[i].first;
    vsum[i].second = sum - vsum[i].first;
    //std::cout << "s: " << i << " " << vsum[i].first << " " << vsum[i].second << std::endl;
  }

  ll rsum = 0;
  for (ll i = N-1; i >= 0; i--) {
    rsum += vp[i].second;
    vrsum[i].first  = C - vp[i].first;
    vrsum[i].second = rsum - vrsum[i].first;
    //std::cout << "r: " << i << " " << vrsum[i].first << " " << vrsum[i].second << std::endl;
  }

  std::vector< ll > vmax (N+1, 0LL);
  std::vector< ll > vrmax(N+1, 0LL);
  vmax[0] = vsum[0].second;
  for (ll i = 1; i < N; i++) {
    vmax[i]  = std::max(vmax[i-1], vsum[i].second);
    //std::cout << "vmax:" << i << " " << vmax[i] << std::endl;
  }

  vrmax[N] = 0;
  for (ll i = N-1; i >= 0; i--) {
    vrmax[i] = std::max(vrmax[i+1], vrsum[i].second);
    //std::cout << "vrmax:" << i << " " << vrmax[i] << std::endl;
  }

  ll ans = 0;
  std::vector< ll > vcal(2, 0LL);
  for (ll i = 0; i < N; i++) {
    vcal[0] = vsum[i].second;
    vcal[1] = vsum[i].second - vsum[i].first  + vrmax[i+1];
    ans = std::max(ans, *std::max_element(vcal.begin(), vcal.end()));
  }

  for (ll i = N-1; i >= 0; i--) {
    vcal[0] = vrsum[i].second;
    vcal[1] = vrsum[i].second - vrsum[i].first + (i == 0 ? 0 : vmax[i-1]);
    ans = std::max(ans, *std::max_element(vcal.begin(), vcal.end()));
  }
  std::cout << ans << std::endl;

  return 0;
}
