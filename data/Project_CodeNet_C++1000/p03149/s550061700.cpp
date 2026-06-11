#include<iostream>
using namespace std;
int main() {
  int a=0,b=0,c=0,d=0;
  for(int i=0;i<4;i++){
    char s;
    cin >> s;
    if(s == '1') a++;
    if(s == '4') b++;
    if(s == '7') c++;
    if(s == '9') d++;
  }
  if(a*b*c*d == 1) cout << "YES";
  else cout << "NO";
  return 0;
}