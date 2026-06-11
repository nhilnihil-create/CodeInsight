#include <iostream>
#include <string>

using namespace std;

int digit_sum(int x) {
  int sum = 0;
  while (x != 0) {
    sum += x % 10;
    x /= 10;
  }

  return sum;
}

int main(int argc, char* argv[]) {
  int N, A, B;
  cin >> N >> A >> B;

  int ret = 0;
  for (int i = 1; i <= N; i++) {
    int sum = digit_sum(i);
    if (A <= sum && sum <= B) {
      ret += i;
    }
  }

  cout << ret << endl;

  return 0;
}
