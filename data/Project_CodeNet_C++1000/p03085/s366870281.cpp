#include<bits/stdc++.h>
using namespace std;

int main(){
  
  char In;
  cin >> In;
  
  switch(In){
    case 'A':
      cout << 'T' << endl;
      break;
    case 'C':
      cout << 'G' << endl;
      break;
    case 'G':
      cout << 'C' << endl;
      break;
    case 'T':
      cout << 'A' << endl;
      break;
    default:
      break;
  }
  return 0;
}
