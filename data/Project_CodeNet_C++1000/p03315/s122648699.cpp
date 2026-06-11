#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int i = 0,j = 0;
  while(j < 4){
    if(s[j] == '-')i = i - 1;
    else i = i + 1;
    j++;
  }
  cout << i;
}
    
     
