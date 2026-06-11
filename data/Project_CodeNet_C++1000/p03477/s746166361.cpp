#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string s;
  if((a + b) > (c + d)){
   	 s = "Left";
  }else if ((a + b) < (c + d)){
     s = "Right"; 
  }else{
   	 s = "Balanced";
  }
  cout << s << endl;
}
