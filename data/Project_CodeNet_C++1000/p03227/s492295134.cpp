#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000


int main() {
  string S;

  cin >> S;

  if (S.size() == 3) reverse(S.begin(), S.end());

  cout << S << endl;

  return 0;
}
