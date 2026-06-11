#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  if((n + 1) / 2 < k)
    cout << "NO";
  else
    cout << "YES";
  cout << endl;

  return 0;
}
