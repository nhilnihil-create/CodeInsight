#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

constexpr double kRate = 380000.0;

int main() {
  double sum = 0;
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    double y; string S; cin >> y >> S;
    if (S == "JPY") sum += y;
    else            sum += y * kRate;
  }
  printf("%lf\n", sum);
}
