#include<iostream>
using namespace std;
int main()
{
  int n,count=0;
  std::cin>>n;
  int num=n;
  while(num)
  {
    if(num%10==2)
      count+=1;
    
    num/=10;
  }
  std::cout<<count;
}