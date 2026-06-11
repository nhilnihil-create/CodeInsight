#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> t(1000);
  t[1] = 1;
  for (int i=2; i<1000; i++) {
    t[i] = t[i-1] + i;
  }
  
  int a, b; cin >> a >> b;
  cout << t[b-a] - b << endl;
  return 0;
}
