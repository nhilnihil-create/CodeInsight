#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<int> l(n);
  for (int i=0; i<n; i++) {
    cin >> l.at(i);
  }
  
  sort(l.begin(), l.end());
  
  int ans = 0;
  for (int i=0; i<(n-1); i++) {
    ans += l[i];
  }

  if (l[n-1] < ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}