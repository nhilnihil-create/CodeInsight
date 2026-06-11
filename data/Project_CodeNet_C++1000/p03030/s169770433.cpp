#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<tuple<string,int,int>> a(n);
  for(int i=1; i<=n; i++) {
    int x;
    string y;
    cin >> y >> x;
    a[i-1] = make_tuple(y, -x, i);
  }
  sort(a.begin(), a.end());
  
  for(auto t : a) {
    int x;
    tie(ignore, ignore, x) = t;
    cout << x << endl;
  }
  return 0;
}