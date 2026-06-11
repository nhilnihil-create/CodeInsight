#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  long long K, A, B;
  cin >> K >> A >> B;

  long long ret = 0;
  long long b_op;
  if ((K - A + 1) % 2 == 0)
    b_op = (K - A + 1) * (B - A) / 2;
  else
    b_op = ((K - A + 1) - 1) * (B - A) / 2 + 1;
  if (b_op > K) {
    ret += b_op + A;
  } else {
    ret += K + 1;
  }

  cout << ret << endl;

  return 0;
}