#include <bits/stdc++.h>
using namespace std;

int main() {
  string x;
  cin >> x;
  
  if( x[0]==x[1] && x[1]==x[2] ){
    cout << "Yes" << endl;
  }
  else if( x[1]==x[2] && x[2]==x[3] ){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}