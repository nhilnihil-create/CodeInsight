#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vec1 z(n);
  for(int i = 0; i < n; i++) cin >> z.at(i);
  vec1 b(m);
  for(int i = 0; i < m; i++) cin >> b.at(i);

  int c = 0;
  for(int i = x+1; i <= y; i++) {
    c = 0;
    for(int j = 0; j < n; j++) {
      if(z.at(j) < i) {
        continue;
      } else {
        c++;
        break;
      }
    }
    if(c == 1) continue;
    c = 0;
    for(int j = 0; j < m; j++) {
      if(b.at(j) >= i) {
        continue;
      } else {
        c++;
        break;
      }
    }
    if(c == 0) {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}