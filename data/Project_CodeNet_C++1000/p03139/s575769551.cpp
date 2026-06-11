#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  if((a+b)<=n)
      printf("%d 0",min(a,b));
  
  else
      printf("%d %d",min(a,b),(a+b)-n);
            
}
