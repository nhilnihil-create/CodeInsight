#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin >> v[i];
    x -= v[i];
  }
  sort(v.begin(), v.end());
 
  while(x>=v[0]) {
    n++;
    x -= v[0];
  }
  cout << n << endl;
  return 0;
}