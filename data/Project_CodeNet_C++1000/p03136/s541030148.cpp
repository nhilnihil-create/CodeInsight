#include <iostream>

using namespace std;

int main () {
   int N;
   cin>>N;
   int x=0,y=0;
   for(int i=0;i<N;i++){
       int L;
       cin>>L;
       x=max(x,L);
       y+=L;
   }
   if (x<(y-x)){
       cout<<"Yes";}
   else{
       cout<<"No";}
   return 0;}
