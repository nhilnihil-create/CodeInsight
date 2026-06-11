#include <bits/stdc++.h>

using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  int cnt=0;
  while(n!=0)
  {
    if(n%10==2)
        cnt++;
    
    n/=10;
  }
  
  printf("%d",cnt);
}
  
  