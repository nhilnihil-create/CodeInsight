#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int X, Y, Z;
  X = 0;
  Y = 0;
  Z = 0;
  for (int i = 0; i < N; i++) {
    int P;
    cin >> P;
    if (P <= A) X++;
    else if (P <= B) Y++;
    else Z++;
  }
  cout << min(min(X, Y), Z) << endl;
}
