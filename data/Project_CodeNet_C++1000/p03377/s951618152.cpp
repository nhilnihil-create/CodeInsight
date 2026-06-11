#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B, X; cin >> A >> B >> X;
  if (X < A || A + B < X) cout << "NO" << endl;
  else                    cout << "YES" << endl;
}
