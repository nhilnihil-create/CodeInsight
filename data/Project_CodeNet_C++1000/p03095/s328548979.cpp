#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
//typedef __int128_t lll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  string s;std::cin >> s;
  vll f(26, 0);
  re(i, n) f[s[i]-'a']++;
  ll ans = 1, P = 1000000007;
  re(i, 26) ans = (ans * (f[i]+1))%P;
  std::cout << (ans==0?P-1:ans-1) << '\n';
  return 0;
}
