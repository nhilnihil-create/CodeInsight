#include <iostream>
 
using namespace std;
 
int main()
{
   int n,k,i,j;int count=0;
   cin>>n>>k;
   for(i=1;i<=n;i++)
   {  int p=0;
       for(j=i;j<=n;j++)
       {   p++;
           
           //cout<<j<<" ";
           if(p==k)
           break;
       }
       if(p==k)
       count++;
      
   }
   cout<<count<<endl;
   
   return 0;
}