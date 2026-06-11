#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  string S ,s;
 for(int i = 0; i < N; i++){
 cin >> S;
  
  if(S != "Y" ){
    s = "Three";
  }
  
  else{
    s = "Four";
    break;
  }
 }
  cout << s << endl;
}
   
 