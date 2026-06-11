#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>


int main() {
  using namespace std;
  int N, K;
  cin >> N >> K;

  long c1 = N / K;
  long c2 = K % 2 == 0 ? (N + K/2)/K : 0;

  cout << c1*c1*c1 + c2*c2*c2 << endl;
}