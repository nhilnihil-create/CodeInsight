#include<bits/stdc++.h>
using namespace std;

int main(void){
   int A,B,C;
   cin>>A>>B>>C;
   if(A<B&&B<C){
      cout<<"No"<<endl;
      return 0;
   }
   if(A>B&&B>C){
      cout<<"No"<<endl;
      return 0;
   }
   if(B<A&&A<C){
      cout<<"No"<<endl;
      return 0;
   }
   if(C<A&&A<B){
      cout<<"No"<<endl;
      return 0;
   }
   cout<<"Yes"<<endl;
   return 0;
}
