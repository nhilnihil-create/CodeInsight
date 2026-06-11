#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

std::vector<ll> find_prime_factors(ll n)
{
    std::vector<ll> result;
    while (n % 2 == 0) {
      result.push_back(2);
      n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
      result.push_back(n);
    }
    return result;
}

int main() {
  ll N;
  ll P;
  cin >> N;
  cin >> P;
  if (N > P) {
    cout << 1 << endl;
    return 0;
  }
  if (N == 1) {
    cout << P << endl;
    return 0;
  }
  ll count = 0;
  vector<ll> sosuu = find_prime_factors(P);

  ll ans = 1;
  std::map<ll, ll> mp;
  rep(i, sosuu.size()){
    auto itr = mp.find(sosuu.at(i));
    if (itr != mp.end()) {
      mp[sosuu.at(i)] = mp[sosuu.at(i)] + 1;
    }
    else
    {
      mp[sosuu.at(i)] = 1;
    }
  }
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    while (itr->second >= N){
      ans *= itr->first;
      itr->second -= N;
    }
  }
    cout << ans << endl;
  return 0;
}
