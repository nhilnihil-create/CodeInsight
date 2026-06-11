#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long double otoshidama;
  string passing;

  long double money = 0;
  for (int i = 0; i < N; ++i) {
    cin >> otoshidama >> passing;
    money += passing == "JPY" ? otoshidama : otoshidama * 380000.0;
  }

  cout << setprecision(20) << money << endl;
  return 0;
}

