#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  
  cin >> a;
  
  if(a.length() == 2){
    cout << a << endl;
  } else {
    std::reverse(a.begin(),a.end());
    cout << a << endl;
  }
}