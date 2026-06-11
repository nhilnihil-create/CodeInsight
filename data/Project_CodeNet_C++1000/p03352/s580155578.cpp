#include<bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  vector<bool> expo(x+1,false);
  expo[1] = true;
  for (int i=2; i<=x; i++) {
    int v = i*i;
    while (v<=x) {
      expo[v] = true;
      v *= i;
    }
  }
  
  for (int i=x; i>=1; i--) {
    if (expo[i]) {
      cout << i << endl;
      return 0;
    }
  }
}