#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  if(s[5]=='0'){
    if(s[6]=='1' || s[6]=='2' || s[6]=='3' || s[6]=='4'){
      cout << "Heisei" << endl;
    }else{
      cout << "TBD" << endl;
    }
  }else{
    cout << "TBD" << endl;
  }
}