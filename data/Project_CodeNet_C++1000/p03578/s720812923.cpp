#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

typedef long double ld;
typedef long long ll;

void print()
{
  std::cout << std::endl;
}

template<class T>
void print(T param)
{
  std::cout << param << std::endl;
  return;
}

template<class T, class... S>
void print(T param1, S... param2)
{
  std::cout << param1 << " "; print(std::forward<S>(param2)...);
}

void fail()
{
  print("NO");
  return;
}

void solve()
{
  ll N;
  std::cin >> N;
  std::map<ll, ll> mp;
  for (ll i = 0; i < N; i++) {
    ll x;
    std::cin >> x;
    mp[x]++;
  }

  ll M;
  std::cin >> M;
  for (ll i = 0; i < M; i++) {
    ll d;
    std::cin >> d;
    if (mp[d] == 0) {
      return fail();
    }
    mp[d]--;
  }

  print("YES");
  return;
}

int main()
{
  solve();
  return 0;
}
