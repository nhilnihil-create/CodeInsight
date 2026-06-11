#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  vector<int> MONEY(25001, 0);
  for(int a = 0; a <= A; ++a) {
    for(int b = 0; b <= B; ++b) {
      for(int c = 0; c <= C; ++c) {
        int val = 500 * a + 100 * b + 50 * c;
        MONEY[val]++;
      }
    }
  }
  cout << MONEY[X] << endl;
  return 0;
}