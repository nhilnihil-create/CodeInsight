#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  ll A, B;
  cin >> A >> B;

  int ans = 1;
  ll x = A;
  while (x * 2 <= B) {
    x *= 2;
    ans++;
  }
  cout << ans << endl;
  return 0;
}