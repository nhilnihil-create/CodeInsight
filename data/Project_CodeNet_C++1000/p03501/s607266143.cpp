#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b, p1, p2;
  cin >> n >> a >> b;
  
  p1 = n * a;
  p2 = b;
  cout << min(p1, p2) << endl;
}