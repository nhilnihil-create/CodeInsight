#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <regex>
#include <numeric>
#include <queue>
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;

int main(int argc, char const *argv[])
{
  ll n, p;
  cin >> n>> p;
  ll radicand = 1;
  ll ans = 1;
  if (n == 1) {
    cout << p << endl;
    return 0;
  }
  while(pow(radicand,n) <= p){
    if (p%(ll)pow(radicand,n) == 0) ans = radicand;
    radicand++;
  }
  cout << ans << endl;
  return 0;
}
