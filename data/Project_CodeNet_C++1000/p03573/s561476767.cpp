#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(3);
  cin >> V[0] >> V[1] >> V[2];
  sort(V.begin(), V.end());
  if (V[0]==V[1]) {
    cout << V[2] << endl;
  }
  else {
    cout << V[0] << endl;
  }
}
