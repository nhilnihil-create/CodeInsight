#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;  /* 整数１、２　１００以内 */
  int c = 0;  /* a,b の平均値の余り */
  
  cin >> a >> b;

  if (a*b > 10000) { 
    cout << "Error!" << endl;
  } else {
    c = (a + b) % 2;
    if (c > 0 ) {
      cout << (a + b) / 2 + 1 << endl;
    }else{
      cout << (a + b) / 2 << endl;
    }
  }
}