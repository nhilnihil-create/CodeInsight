#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lld a, b, c;
  cin >> a >> b >> c;
  lld ans = 0;
  cout << b + (min (c, a+b+1)) << "\n";
  return 0;
}