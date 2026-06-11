#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort(v.rbegin(), v.rend());
  cout << sum - v[0]/2 << endl;
  return 0;
}