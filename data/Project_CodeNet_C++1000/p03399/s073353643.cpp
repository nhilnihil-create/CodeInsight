#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B, C, D; cin >> A >> B >> C >> D;
  cout << min(A, B) + min(C, D) << endl;
}
