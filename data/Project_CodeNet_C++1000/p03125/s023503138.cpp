#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (b % a == 0 ? a + b : b - a) << endl;
  return 0;
}
