#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  int m=0;
  for(int i=0; i<4; i++) {
    cin >> c;
    if (c=='+') {m++;}
    else {m--;}
  }
  cout << m << endl;
}
