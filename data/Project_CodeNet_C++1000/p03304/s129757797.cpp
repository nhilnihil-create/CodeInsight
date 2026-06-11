#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  long long n, m, d;
  cin >> n >> m >> d;
  double result;
  if (d == 0) {
    result = (m-1.0)/n;
  } else {
    result = (2.0*(n-d)*(m-1.0))/(n*n);
  }
  cout <<  fixed << setprecision(20) << result << endl;
}