#include<iostream>
using namespace std;
int main(){
  char s[10];
  cin >> s;
  if(s[5] == '0' && s[6] <= '4') cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}