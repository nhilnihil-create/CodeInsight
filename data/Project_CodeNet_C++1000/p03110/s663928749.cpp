#include <iomanip>
#include <iostream>

using namespace std;


int main() {
  int N;
  cin >> N;
  double tot{};
  string cur;
  double x;
  for (int i = 0; i < N; i++) {
    cin >> x >> cur;
    if (cur == "JPY") {
      tot += x;
    } else {
      tot += x * 380000.;
    }
  }

  cout << fixed << setprecision(16)
       << tot << endl;
  return 0;
}
