
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,c,max;
  string e;
  max = 0;
  cin >> n;
  vector<string> r(n);
  for(int i = 0; i < n; i++) {
    cin >> r.at(i);
  }
  cin >> m;
  vector<string> b(m);
  for(int i = 0; i < m; i++) {
    cin >> b.at(i);
  }
  for(int i = 0; i < n; i++) {
    c = 0;
    e = r.at(i);
    for(int j = 0; j < n; j++) {
      if(r.at(j) == e) {
        c++;
      }
    }
    for(int t = 0; t < m; t++) {
      if(b.at(t) == e) {
        c--;
      }
    }
    if(max < c) {
      max = c;
    }
  }
  cout << max << endl;   
}