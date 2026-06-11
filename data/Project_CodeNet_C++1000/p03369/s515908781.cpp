#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  int price = 700;
  for (int i = 0; i < 3; ++i) {
    if (S[i] == 'o') price += 100;
  }
  cout << price << endl;
}
