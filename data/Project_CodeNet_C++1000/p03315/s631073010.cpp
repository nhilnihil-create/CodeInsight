#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int p = 0;
  int m = 0;
  int i;
  for(i=0;i<4;i++){
    if(s[i]=='+') p++;
    else m++;
  }
  cout << p-m << "\n";
  return 0;
}