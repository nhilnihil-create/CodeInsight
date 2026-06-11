#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  bool as=false;
  bool bs=false;
  bool cs=false;

  for(int i=0; i<3; i++){
    cin >> S;
    if(S=='a'){
      as=true;
    }
    else if(S=='b'){
      bs=true;
    }
    else if(S=='c'){
      cs=true;
    }
  }

  if(as==true && bs==true && cs==true){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

return 0;  
}