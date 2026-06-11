#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int ab, bc, ca; cin >> ab >> bc >> ca;
  int a = ab * bc, b = bc * ca, c = ca * ab;
  int vmin = min(min(a, b),  c);
  cout << vmin / 2  << endl;
}
