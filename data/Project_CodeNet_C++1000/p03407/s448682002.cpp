#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B, C; cin >> A >> B >> C;
  if (A + B >= C) cout << "Yes" << endl;
  else            cout << "No" << endl;
}
