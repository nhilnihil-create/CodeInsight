#include<iostream>
using namespace std;

int sumOfEachDigit(int num) {
  int sum = 0;
  while (num != 0)
  {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;

  int ans = sumOfEachDigit(N);
  if (ans == 1) ans *= 10;
  cout << ans << endl;

  return 0;
}
