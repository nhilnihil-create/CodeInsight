#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  //似ている整数列全体数
  ll all = 1;
  for (int i = 1; i <= N; i++) {
    all *= 3;
  }
  //このうち全部奇数のやつ
  ll kisu = 1;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (A%2 == 1) {
      kisu *= 1;
    }
    else {
      kisu *= 2;
    }
  }
  
  cout << all - kisu << endl;
}
