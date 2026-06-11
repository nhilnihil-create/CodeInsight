#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double x;
    char u[4];
    cin >> x >> u;
    sum += u[0] == 'J' ? x : x * 380000;
  }
  printf("%f",sum);
}
