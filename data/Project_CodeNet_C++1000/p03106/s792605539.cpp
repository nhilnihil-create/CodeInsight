#include <iostream>
using namespace std;
int main() {
   int a,b,k;
   cin>>a>>b>>k;
  int  count=0;
   int i=0;
   
   if(a>b)
   {
        swap(a,b);
   }
   i=a+1;
 
while(count!=k)
{
   i--;
    if(a%i==0&&b%i==0)
    {
        count++;
    }
   
}
cout<<i<<endl;
}
