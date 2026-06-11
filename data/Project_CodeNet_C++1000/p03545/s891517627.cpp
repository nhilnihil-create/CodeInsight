#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int G;cin>>G;
  int A=G/1000;
  int B=(G/100)%10;
  int C=(G/10)%10;
  int D=G%10;
  if(A+B+C+D==7){
    cout<<A<<'+'<<B<<'+'<<C<<'+'<<D<<'='<<7<<endl;
  }
  else if(A+B+C-D==7){
    cout<<A<<'+'<<B<<'+'<<C<<'-'<<D<<'='<<7<<endl;
  }
  else if(A+B-C+D==7){
    cout<<A<<'+'<<B<<'-'<<C<<'+'<<D<<'='<<7<<endl;
  }
  else if(A+B-C-D==7){
    cout<<A<<'+'<<B<<'-'<<C<<'-'<<D<<'='<<7<<endl;
  }
  else if(A-B+C+D==7){
    cout<<A<<'-'<<B<<'+'<<C<<'+'<<D<<'='<<7<<endl;
  }
  else if(A-B+C-D==7){
    cout<<A<<'-'<<B<<'+'<<C<<'-'<<D<<'='<<7<<endl;
  }
  else if(A-B-C+D==7){
    cout<<A<<'-'<<B<<'-'<<C<<'+'<<D<<'='<<7<<endl;
  }
  else if(A-B-C-D==7){
    cout<<A<<'-'<<B<<'-'<<C<<'-'<<D<<'='<<7<<endl;
  }
}
