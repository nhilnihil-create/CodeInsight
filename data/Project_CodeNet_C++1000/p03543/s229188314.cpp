#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a, b, c, d;
  cin >> N;
  
  a = N / 1000;
  b = (N - a*1000) / 100;
  c = (N - a*1000 - b*100) / 10;
  d = N - a*1000 - b*100 - c*10;
  if (N < 1000 || N > 9999){
    cout << "No" << endl;
  }
  else if (a == b && a == c) {
    cout << "Yes" << endl;
  }
  else if (b == c && b == d) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}