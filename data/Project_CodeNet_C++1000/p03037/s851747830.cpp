#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<int> l(m), r(m);
  for(int i = 0; i < m; i++) {
    cin >> l.at(i) >> r.at(i);
  }
  sort(l.begin(), l.end());   sort(r.begin(), r.end());
  if(r.at(0) - l.at(m -1) < -1) {
    cout << 0 << endl;
  }
  else {
    cout << r.at(0) - l.at(m -1) +1 << endl;
  }
}