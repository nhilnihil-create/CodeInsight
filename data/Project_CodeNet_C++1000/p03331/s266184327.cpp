#include <iostream>
using namespace std;

int main() {
  int i,j,n,k,a,b,aa=0,bb=0,min=100000000;
  cin>>n;
  for(i=1;i<n;i++){
    a=i;
    b=n-i;
    aa=0;
    bb=0;
    while(a>0){
      aa+=a%10;
      a/=10;
    }
    while(b>0){
      bb+=b%10;
      b/=10;
    }
    if(aa+bb<min){
      min=aa+bb;
    }
   // cout<<aa<<" "<<bb<<" "<<min<<endl;
  }
  
  cout<<min<<endl;
    
}