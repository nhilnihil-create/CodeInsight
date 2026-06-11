#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  int k = 0;
  for (int i = 100; i >= 1; --i) {
    if (A%i==0 && B%i==0) ++k;
    if (k==K) {
      cout << i << endl;
      return 0;
    }
  }
  return 1;
}