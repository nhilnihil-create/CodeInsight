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
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int count = 0;
  // 0 <= a, b, c <= 50. bruteforce is ok.
  // O(n^3)
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 0; k <= c; ++k) {
        if (500*i+100*j+50*k == x) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
