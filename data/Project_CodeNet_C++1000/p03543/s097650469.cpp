#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, a, b, c, d;
  cin  >> N;
  a = N/1000, b = (N-1000*a)/100,
  c = (N-1000*a-100*b)/10, d = (N-1000*a-100*b-10*c);

  if ( b != c ) {
      cout << "No" << endl;
  }

  else if ( a != b && c != d) {
    cout << "No" << endl;
  }
  
  else {
    cout << "Yes" << endl;
  }
  
}