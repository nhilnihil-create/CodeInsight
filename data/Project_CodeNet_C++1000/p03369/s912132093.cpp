#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  int bill=700;

  for(int i=0; i<3; i++){
    cin >> S;
    if(S=='o'){
      bill+=100;
    }
  }  

  cout << bill << endl;

return 0;  
}