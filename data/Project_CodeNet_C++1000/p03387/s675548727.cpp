#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;
  cin >> A >> B >> C;
  if(A>B){
    swap(A,B);
  }
  if(B>C){
    swap(B,C);
  }
  if(A>B){
    swap(A,B);
  }
  int count=0;
  D=0;
  while(C-1>A){
    A+=2;
    count++;
  }
  while(C-1>B){
    B+=2;
    count++;
  }
  if(A==C){
    D++;
  }
  if(B==C){
    D++;
  }
  if(D==2){
    cout << count << endl;
  }
  else if(D==1){
    cout << count+2 << endl;
  }
  else{
    cout << count+1 << endl;
  }
}
    
  