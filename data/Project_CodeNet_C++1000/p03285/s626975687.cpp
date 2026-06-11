#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
#define    in   cin>>
using namespace std;

int main()
{
  int n,ans=0;
  in n;
  bool flag=false;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(4*i+7*j==n)flag=true;
    }
  }
  if(flag==true)py;
  else pn;
}
