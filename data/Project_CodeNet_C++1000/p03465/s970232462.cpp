#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f

bitset<4000020> f; //最多2000个数，每个数最大值为2000
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  std::cin >> n;
  f[0] = 1;
  int s = 0;
  while (n--) {
    int tmp;
    std::cin >> tmp;
    f |= f << tmp;
    s += tmp;
  }

  for (int i = (s + 1) / 2; i <= s; ++i)
    if (f[i]) {
      std::cout << i << '\n';
      break;
    }
  return 0;
}
