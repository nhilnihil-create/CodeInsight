#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string S;
  cin >> a >> b >> S;
  for(int i=1;i<=a;i++){
    if(i==b){
      if(S.at(i-1)=='A'){
        S.at(i-1)='a';
      }
      else if(S.at(i-1)=='B'){
        S.at(i-1)='b';
      }
      else{
        S.at(i-1)='c';
      }
    }
    cout << S.at(i-1);
  }
  cout << endl;
}
