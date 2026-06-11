#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;
  double ans = 0;
  for (int i = 0; i < N; i++) {
    double x;
    cin >> x;
    string cur;
    cin >> cur;

    if (cur == "BTC") {
      x *= 380000.0;
    }
    ans += x;
  }

  cout << fixed << setprecision(5) << ans << endl;
  return 0;
}