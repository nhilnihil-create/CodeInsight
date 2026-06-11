#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  
  for(int i = 0; i < k; i++) {
    int d = max(a,b);
    d = max(d,c);
    if(a == d) {
      a = a * 2;
      continue;
    }
    if(b == d) {
      b = b * 2;
      continue;
    }
    if(c == d) {
      c = c * 2;
      continue;
    }
  }
  cout << a+b+c << endl;
}