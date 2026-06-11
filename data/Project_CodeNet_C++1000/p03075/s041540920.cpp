#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int a, b, c, d, e, k; cin >> a >> b >> c >> d >> e >> k;
  if (e - a <= k) cout << "Yay!" << endl;
  else           cout << ":(" << endl;
}
