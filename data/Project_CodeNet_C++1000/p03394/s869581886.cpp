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

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  if(n == 3){
    cout << "2 5 63" << endl;
    return 0;
  }else if(n == 4){
    cout << "2 5 20 63" << endl;
    return 0;
  }
  ll sum = 0;
  int curr = 2;
  vector<int> vec;
  while(vec.size() < n){
    if(curr % 2 == 0 || curr % 3 == 0){
      vec.pb(curr);
      sum += curr;
    }
    curr++;
  }
  if(sum % 6 == 2){
    while(curr % 6 != 0)curr++;
    vec[4] = curr;
  }else if(sum % 6 == 3){
    while(curr % 6 != 0)curr++;
    vec[5] = curr;
  }else if(sum % 6 == 5){
    while(curr % 6 != 3)curr++;
    vec[4] = curr;
  }
  sort(vec.begin(), vec.end());
  rep(i, n){
    cout << vec[i];
    if(i == n - 1)cout << endl;
    else cout << " ";
  }
	return 0;
}
