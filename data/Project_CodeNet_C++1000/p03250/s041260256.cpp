#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll res = max({a,b,c}) * 10;
  res += a + b + c - max({a,b,c});
  cout << res << endl;
}