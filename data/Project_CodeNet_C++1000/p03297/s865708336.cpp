#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
  cin>>T;
  for(int i=0;i<T;i++){
  int64_t A,B,C,D;
    cin>>A>>B>>C>>D;
    if(A<B || D<B)
      cout<<"No"<<endl;
    else{
       if(B<=C)
         cout<<"Yes"<<endl;
      else{
      int64_t g=gcd(D,B);
        int64_t a=A%B;
        if(C<a)
          cout<<"No"<<endl;
        else{
        int64_t x=(C-a+g)/g;
          if(x*g+a<B)
            cout<<"No"<<endl;
          else
            cout<<"Yes"<<endl;
        }
      }
    }
   }
   return 0;
}