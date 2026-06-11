#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main()
{
  int a,b,sum;
  cin>>a>>b;
  for(int i=a;i<=b;i++)
  {
    int n=i;
     sum=0;
     while(n)
     {
       int r=n%10;
       sum=sum*10+r;
        n/=10;

     }
     if(sum==i) cnt++;

  }


   cout<<cnt<<'\n';




    return 0;

}