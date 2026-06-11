#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for(int i=0; i<m; i++) cin >> b[i];
  int count = 0;
  for(int i=0; i<n; i++) {
    int wa = 0;
    for(int j=0; j<m; j++) {
      int x;
      cin >> x;
      wa += x*b[j];
      if(j == m-1 && wa+c > 0)
        count++;
    }
  }
  cout << count << endl;
  return 0;
}