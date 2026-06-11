#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;


typedef long long ll;
int main() {
  int m, k;
  cin >> m >> k;
  int max = 1 << m;
  if (k >= max) {
    cout << "-1" << endl;
    return 0;
  }
  if (m == 0) { 
    cout << "0 0" << endl;
    return 0;
  }
  if (m == 1) {
    if (k == 1) {
      cout << "-1" << endl;
    }
    else {
      cout << "0 0 1 1" << endl;
    }
    return 0;
  }
  for (int i = 0; i < max; ++i) { 
    if (i == k) continue;
    cout << i << " ";
  }
  cout << k << " ";
  for (int i = max-1; i >= 0; --i) { 
    if (i == k) continue;
    cout << i << " ";
  }
  cout << k << endl;
}
