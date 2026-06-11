#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B,C,D;
  cin >> A >> B >> C >> D;
  if(A>B){
    swap(A,B);
  }
  if(B>C){
    swap(B,C);
  }
  if(C>D){
    swap(C,D);
  }
  if(B>C){
    swap(B,C);
  }
  if(A>B){
    swap(A,B);
  }
 if(A==1 && B==4 && C==7 && D==9){
   cout << "YES" << endl;
 }
  else{
    cout << "NO" << endl;
  }
}