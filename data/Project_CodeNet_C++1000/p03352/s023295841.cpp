#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  bool nums[1001] = {false};

  nums[1] = true;
  for (int b = 2; b <= 32; ++b) {
    for (int e = 2; pow(b, e) <= 1000; ++e) {
      nums[(int)pow(b, e)] = true;
    }
  }
  double n;
  cin >> n;

  for (int i = n; i >= 1.0; --i) {
    if (nums[i]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
