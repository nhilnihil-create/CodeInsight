#include <bits/stdc++.h>
using namespace std;
int main() {
  char X,Y;
  cin >> X >> Y;
  
  if (X-'0' < Y-'0'){
    cout << '<' << endl;
  }
  else if (X-'0' > Y-'0'){
    cout << '>' << endl;
  }
  else {
    cout << '=' << endl;
  }
}
  
 