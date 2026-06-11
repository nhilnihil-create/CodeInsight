#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string T=S.substr(0,2);
  string U=S.substr(2,2);
  int A=stoi(T);
  int B=stoi(U);
  if(0<A && A<13 && 0<B && B<13){
    cout << "AMBIGUOUS" << endl;
  }
  else if(0<A && A<13){
    cout << "MMYY" << endl;
  }
  else if(0<B && B<13){
    cout << "YYMM" << endl;
  }
  else{
    cout << "NA" << endl;
  }
}
  