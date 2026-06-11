#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  int bill=0;

  for(int i=0; i<3; i++){
    cin >> S;
    if(S=='o'){
      bill++;
    }
  }  

  cout << 700+(bill*100) << endl;

return 0;  
}