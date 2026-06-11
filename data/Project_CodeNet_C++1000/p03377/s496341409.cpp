#include <iostream>
 
using namespace std;
 
int main()
{
  int a,b,x;
  cin>>a>>b>>x;
  while(x>0)
  {
    if (x>a+b||x<a)
    {
      cout<<"NO";
      break;
    }
    else if (x!=a||x==a){
      a+=1;
      b-=1;
      cout<<"YES";
      break;
    }
  }
}