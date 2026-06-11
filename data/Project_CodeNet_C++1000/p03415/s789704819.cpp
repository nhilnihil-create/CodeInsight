#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> a(9);
    
  for (int j = 0; j < 9 ; j++) {
    cin >> a.at(j);
  }
  
  cout << a.at(0) << a.at(4) << a.at(8) << endl; 
}