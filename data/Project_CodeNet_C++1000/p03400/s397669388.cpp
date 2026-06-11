#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, D, X;
  cin >> N >> D >> X;
  int SUM = 0;
  rep(i, N) {
    int A;
    cin >> A;
    SUM += ((D - 1) / A) + 1;
  }
  cout << X + SUM << endl;
  return 0;
}