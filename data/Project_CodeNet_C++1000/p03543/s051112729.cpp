#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  char check;
  cin >> N;
  check = N[1];
  if((N[0]==check && N[2]==check) || (N[2] == check && N[3] == check)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
    
}