#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 120, task c, 2020/09/13
//ms,

/*
*/

int main(void){
  string S;
  cin >>S;
  int r=0;
  int b=0;
  for(size_t i=0;i<S.size();i++){
    if(S.at(i)=='0') r++;
    else b++;
  }
  cout <<2*min(r,b)<<endl;
  return 0;
}
/*
*/
