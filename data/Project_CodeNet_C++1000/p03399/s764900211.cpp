#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int x,y;
    if(A <= B){
      x=A;
    }if(A > B){
      x=B;
    }if(C <= D){
     y=C;
    }if(C > D){
     y=D;
    }cout<<x+y<<endl;
}