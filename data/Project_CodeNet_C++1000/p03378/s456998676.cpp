#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> v(m);
  int count = 0;
  for(int i=0; i<m; i++) {
    cin >> v[i];
    if(x<v[i]) count++;
  }
  cout << min(count, m-count) << endl;
  return 0;
}