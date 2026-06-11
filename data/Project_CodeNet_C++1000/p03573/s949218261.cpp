#include<iostream>
using namespace std;  
int main(){
     int A,B,C;
     cin>>A>>B>>C;
     if(B==C && A != B ){
          cout<<A;
     }
     else if( A==C && B != A ){
          cout<<B;
     }
     else if(A==B && C!=A){
          cout<<C;
     }

}
