#include <iostream>
using namespace std;
int main(){
  string n;
  cin >> n;
  int i;
  for(i=0;i<3;i++){
    if(n[i]=='1') cout << '9';
    else if(n[i]=='9') cout << '1';
  }
  cout << "\n";
  return 0;
}