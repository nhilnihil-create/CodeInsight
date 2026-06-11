#include <bits/stdc++.h>
using namespace std;

int main() {
 
  char a, b, c, d;
  cin >> a >> b >> c >> d;
    
  if ((a == b)&&(b == c) ){
   cout << "Yes" << endl; 
  }
  else if ((c == b)&&(b == d) ){
   cout << "Yes" << endl; 
  }
  else {
    cout << "No" << endl; 
  }
  // ここにプログラムを追記
}
