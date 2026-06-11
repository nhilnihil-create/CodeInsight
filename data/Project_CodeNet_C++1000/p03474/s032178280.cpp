#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int A,B;
  string S;
  cin >> A >> B >> S;

  for(int i=0;i<A;i++){
    if(!('0'<=S.at(i) && S.at(i)<='9')){
      cout << "No" << endl;
      return 0;
    }
  }

  if(S.at(A)!='-'){
    cout << "No" << endl;
    return 0;
  }

  for(int i=A+1;i<A+B+1;i++){
    if(!('0'<=S.at(i) && S.at(i)<='9')){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  
  return 0;
}
