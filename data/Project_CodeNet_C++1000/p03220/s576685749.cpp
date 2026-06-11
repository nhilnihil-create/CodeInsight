#include <iostream>

using namespace std;

int main() {
  int N, A;
  double T;
  cin >> N >> T >> A;

  double diff = 100000;
  int res = -1;
  for (int n = 1; n <= N; ++n) {
    double H;
    cin >> H;
    double t = T - H * 0.006;
    double d = abs(A-t);
    if (d < diff) {
      diff = d;
      res = n;
    }
  }
  cout << res << endl;
  
  return 0;
}
