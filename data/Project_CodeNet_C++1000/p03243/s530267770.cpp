#include <bits/stdc++.h>
 
using namespace std;
 
int digit(int n)
{
  set<int> s;
  while(n!=0)
  {
    s.insert(n%10);
    n/=10;
  }
  
  if(s.size()==1)
      return 1;
  
  else
     return 0;
}
int main()
{
   int i,n;
   cin>>n;
  
   for(i=n;;++i)
   {
       if(digit(i))
           break;
     
   }
  
  cout<<i;
}