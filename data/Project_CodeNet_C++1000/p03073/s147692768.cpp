#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ansA = 0;
  int ansB = 0;
  
  for(int i=0; i<S.size(); i++){
    if(S.at(i)=='0'){
    if(i%2==0)ansA ++;
    else ansB ++;
    }
    if(S.at(i)=='1'){
      if(i%2==1)ansA ++;
      else ansB ++;
    }
  }
  
  cout << min(ansA, ansB) << endl;
}
