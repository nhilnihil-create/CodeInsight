#include <iostream>

using namespace std;

int main()
{
    int n,k,s;
    cin>>n>>k;
    s=(n%k);
   if(s==0){
    cout<<0;
   }
   else{
    cout<<1;
   }

}
