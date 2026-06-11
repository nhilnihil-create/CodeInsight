#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main() {
  char X, Y;
  cin >> X >> Y;
  
  if ((int)X < (int)Y) cout << '<' << endl;
  else if((int)Y < (int)X) cout << '>' << endl;
  else cout << '=' << endl;
}