#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int a, b; cin >> a >> b;
  if (a > b) cout << a-1 << endl;
  else       cout << a << endl;
}
