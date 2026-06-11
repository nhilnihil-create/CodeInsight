#include <iostream>
#include <vector>

using namespace std;

int main () {
  int n;
  cin >> n;

  if (n == 3) {
    cout << 2 << " " << 5 << " " << 63 << endl;
    return 0;
  }
  
  vector<int> cnts (7, 0);
  cnts[3] = n / 4;
  if (cnts[3] % 2 == 1) cnts[3]++;
  cnts[2] = n / 4;
  cnts[4] = n / 4;
  cnts[6] = n - cnts[3] - cnts[2] - cnts[4];

  if (cnts[6] == 5001) {
    cnts[6] -= 2;
    cnts[2]++;
    cnts[4]++;
  }

  int mx = 0;
  for (int k = 1; k <= 6; k++) {
    for (int i = 0; i < cnts[k]; i++) {
      mx = max(mx, 6 * i + k);
      cout << 6 * i + k << " ";
    }
  }
  cerr << mx << endl;
  cout << endl;
}
