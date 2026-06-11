#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if(n <= 3) {
    cout << "No" << endl;
    return 0;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {  
      if(n == i*4+j*7) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}