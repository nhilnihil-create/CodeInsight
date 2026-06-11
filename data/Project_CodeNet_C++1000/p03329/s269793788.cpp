#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int count_by_mul(int money, int mul) {
  int count = 0;

  while(money >= mul) {
    int num = mul;
    while (money >= num * mul) {
      num *= mul;
    }

    money -= num;
    count++;
  }
  count += money;

  return count;
}

int main() {
  int N;
  cin >> N;

  int mn = N;
  for(int i=0; i<=N; i++) {
    int count = count_by_mul(i, 6) + count_by_mul(N - i, 9);
    if (mn > count) mn = count;
  }

  cout << mn << endl;

  return 0;
}
