#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<char> a(6);
  
  for ( int i = 0; i < 6; i++){
    cin >> a.at(i);
  }
  
  
  
  if ( (a.at(0) == a.at(5)) && (a.at(1) == a.at(4)) && (a.at(2) == a.at(3)) ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
  
}

