#include <iostream>

using namespace std;

int main()
{
   int n,k,c=0;
   cin>>n>>k;
   c=n%k;
   if(c==0){
    cout<<0;
   }
   else{
    cout<<1;
   }
    return 0;
}
