#include <bits/stdc++.h>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

void print(){ std::cout << std::endl; }
template <typename Head> void print(Head&& head) { std::cout << head << std::endl; }
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail)
{
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...); // or print(tail...);
}

int main(int argc, char* argv[])
{
  std::string s;
  std::cin >> s;

  ll size = (ll)s.size();
  ll ans = size;
  for (ll i = 1; i < size; i++) {
    if (s[i-1] != s[i]) {
      ans = std::min(ans, std::max(size - i, i));
    }
  }

  print(ans);
  return 0;
}
