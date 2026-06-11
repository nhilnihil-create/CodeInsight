#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int a,b,ab;
  
  long ans=A*X+B*Y;
  for(int i=0; i<=2*max(X,Y); i++){
    a=X-(max(X,Y)==X?i/2:X-i/2>=0?i/2:X);
    b=Y-(max(X,Y)==Y?i/2:Y-i/2>=0?i/2:Y);
    
    if(ans>A*a+B*b+C*i){
      ans=A*a+B*b+C*i;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}