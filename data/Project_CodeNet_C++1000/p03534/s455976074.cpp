#include <bits/stdc++.h>
using namespace std;

int main(){
  int a=0,b=0,c=0;
  string S;
  cin >> S;
  for(int i=0;i<S.length();i++){
    if(S[i]=='a'){a++;}
    else if(S[i]=='b'){b++;}
    else{c++;}
  }
  if((abs(a-b)<=1) && (abs(a-c)<=1) && (abs(b-c)<=1)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
