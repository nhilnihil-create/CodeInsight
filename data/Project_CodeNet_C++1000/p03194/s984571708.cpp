#include<iostream>
#include<math.h>
using namespace std;

int main()
{
 long n,p,ans=1,st;
 cin >> n >> p;
 if(n==1)
 {
  cout << p << endl;
  return 0;
 }
 st = sqrt(p)+1;
 for(long i=2;i<st;i++)
 {
  while(p % long(pow(i,n))==0)
  {
   ans*=i;
   p = p/pow(i,n);
  }
 }
 cout << ans << endl;
 return 0;
}