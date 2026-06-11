#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  for(int i=0;i<3;i++){
    char a;
    cin >> a;
    if(a=='1') s+='9';
    else if(a=='9') s+='1';
    else s+=a;
  }
  cout << s << endl;
}