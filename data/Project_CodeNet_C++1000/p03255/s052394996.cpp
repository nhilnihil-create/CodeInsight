#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}
typedef __int128_t it;
int main(int argc, char const *argv[]) {
  it n, x;
  ll o, p;std::cin >> o >> p;
  n = o, x = p;
  vector<it> a(n);
  for(int i=0;i<n;i++) scanf("%lld", &o), a[i] = o;
  it ans = 1000000000000000000;
  ans = ans * ans;
  vector<it> L(n, 0);
  L[0] = a[n-1];
  for(int i=1;i<n;i++) L[i] = L[i-1] + a[n-1-i];

  for(it k=1;k<=n;k++){
    it cost = (n+k)*x, tmp = 0;
    it tm = (n/k)+(n%k?1:0);
    for(it j=1;j<=tm;j++){//j番目に取る
      it y = (j==1?5:(2*j + 1));
      ll st = (j-1) * k;
      st = (st==0?0:L[st-1]);
      ll ed = L[min(n, j*k)-1];
      tmp += y * (ed - st);
    }
    //std::cout << k << " " << cost << " " << tmp << '\n';
    ans = min(ans, cost + tmp);
  }
  std::cout << ans << '\n';
  return 0;
}
