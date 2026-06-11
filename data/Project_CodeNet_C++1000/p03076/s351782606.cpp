#include <iostream>
#include <vector>
using namespace std;

int main () {
   vector<int>A(5);
   int x=0;
   for(int i=0;i<5;i++){
       cin>>A[i];
       x+=(A[i]+9)/10*10;
   }
   int y = x;
   for(int i=0;i<5;i++){
       if(A[i]%10>0)
           y=min(y,(x-10)+A[i]%10);
   }
   cout<<y<<endl;
    return 0;}
