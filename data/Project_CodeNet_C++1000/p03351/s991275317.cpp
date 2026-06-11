#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,E,F,G,H,I,J;
  cin >> A >> B >> C >> D;
  E=max(A,B)-min(A,B);
  F=max(A,C)-min(A,C);
  G=max(C,B)-min(C,B);
  if(F<=D){
    cout << "Yes" << endl;
  }
  else if(E<=D&&G<=D){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}