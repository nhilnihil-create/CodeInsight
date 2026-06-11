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
  return;
}

void solve()
{
  ll K, A, B;
  std::cin >> K >> A >> B;

  ll ans = 0LL;
  if (B >= A + 2) {
    ans += A;
    K -= A - 1;
    if (K % 2 == 1) ans++;
    K /= 2;
    ans += K * (B-A);
  } else {
    ans = K + 1;
  }
  print(ans);
  return;
}

int main()
{
  solve();
  return 0;
}
