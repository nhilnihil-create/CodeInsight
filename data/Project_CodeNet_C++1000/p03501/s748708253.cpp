#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b, c;
  cin >> n >> a >> b;
  c = a * n;
  if (c <= b){
    cout << c << endl;
  }
  else {
    cout << b << endl;
  }
}