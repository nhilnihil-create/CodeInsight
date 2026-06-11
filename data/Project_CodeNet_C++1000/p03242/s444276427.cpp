#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  string N;
  cin >> N;

  for (int i = 0; i < 3; i++) {
    if (N.at(i) == '1')
      N.at(i) = '9';
    else
      N.at(i) = '1';
  }

  cout << N << endl;
}