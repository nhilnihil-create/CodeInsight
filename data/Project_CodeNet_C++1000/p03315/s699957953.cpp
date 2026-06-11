#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  int Num = 0, i;
  
  for(i = 0; i < 4; i++){

    if(S[i] == '+'){
      Num++;
    }else{
      Num--;
    }
  }
  cout << Num << endl;
  return 0;
}