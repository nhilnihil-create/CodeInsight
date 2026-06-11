#include <iostream>

int gcd(int m,int n)
{
  if(m<n)
  {
    int t=m;
    m=n;
    n=t;
  }
  
  for(;;)
  {
    if(n==0)
      return m;
    
    int t=m%n;
    m=n;
    n=t;
  }
}

int main()
{
  int A,B,K;
  std::cin>>A>>B>>K;
  
  int g=gcd(A,B);
  
  int count=0;
  for(int i=g;i!=0;i--)
  {
    if(g%i==0)
    {
      count++;
      if(count==K)
      {
        std::cout<<i<<std::endl;
        break;
      }
    }
  }
  
  return 0;
}