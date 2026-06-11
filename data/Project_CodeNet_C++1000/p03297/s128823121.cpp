// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve
ll gcd(ll x, ll y){
  if(x > y)return gcd(y, x);
  if(x == 0)return y;
  return gcd(y % x, x);
}

int main(int argc, char const* argv[])
{
  int t;
  cin >> t;
  rep(i, t){
    ll a[4];
    rep(j, 4)cin >> a[j];
    if(a[0] < a[1]){
      cout << "No" << endl;
    }else if(a[1] > a[3]){
      cout << "No" << endl;
    }else if(a[2] >= a[1]){
      cout << "Yes" << endl;
    }else{
      ll g = gcd(a[1], a[3]);
      if(a[2] < a[1] - g + (a[0] % g))cout << "No" << endl;
      else cout << "Yes" << endl;
    }
  }
	return 0;
}
