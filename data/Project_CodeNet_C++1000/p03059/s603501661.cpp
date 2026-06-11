#include<iostream>
using namespace std;

int main() {
  int A, B, T;
  cin >> A >> B >> T;
  int sum_t;
  sum_t = T + 0.5;
  cout << (sum_t / A ) * B;
}