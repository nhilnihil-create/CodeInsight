#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, l; cin >> n >> l;
  vector<int> c;
  vector<int> t;
  for (int i=0; i<n; i++) {
    int tmpc, tmpt;
    cin >> tmpc >> tmpt;
    if (tmpt <= l) {
      c.push_back(tmpc);
      t.push_back(tmpt);
    }
  }
  
  if (c.size() == 0) {
    cout << "TLE" << endl;
    return 0;
  }
  
  int minc = 1001;
  for (int i=0; i<c.size(); i++) {
    if (c[i] < minc) minc = c[i];
  }
  
  cout << minc << endl;
  return 0;
}