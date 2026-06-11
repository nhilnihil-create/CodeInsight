#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> v(3);
  for(int i=0; i<3; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  int k;
  cin >> k;
  for(int i=0; i<k; i++) v[0] *= 2;
  cout << v[0]+v[1]+v[2] << endl;
  return 0;
}