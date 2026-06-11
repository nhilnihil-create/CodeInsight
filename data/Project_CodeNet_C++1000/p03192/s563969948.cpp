#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

int main()
{
    int n,count=0;
    scanf("%d",&n);
    while(n)
    {
      if(n%10==2)
        count++;
      n/=10;
    }
    printf("%d\n",count);
    return 0;
}
