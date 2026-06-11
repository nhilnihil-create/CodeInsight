#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int A, B;
  cin >> A >> B;

  int plus = A + B;
  int minus = A - B;
  int product = A * B;

  cout << max({plus, minus, product}) << endl;
}