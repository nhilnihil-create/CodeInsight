#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  
  if(s == "ooo"){
    cout << "1000" << endl;
  }
  
  else if( s == "xoo" || s == "oxo" || s == "oox" ) {
    cout << "900" << endl;
  }
  
  else if( s == "oxx" || s == "xox"|| s == "xxo" ){
    cout << "800" << endl;
  }
  
  else{
    cout << "700" << endl;
  }
  
}
