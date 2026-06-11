#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  
  vector<int64_t> L(86+1);
  L[0] = 2;
  L[1] = 1;
  for (int i=2; i<86+1; i++) L[i] = L[i-1] + L[i-2];
  cout << L[n] << endl;
}
