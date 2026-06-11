#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,b;
    cin>>n>>m>>b;
     if(m+b>=n)
     {
         printf("%d %d\n",min(m,b),m+b-n);
     }
     else
     {
         printf("%d %d\n",min(m,b),0);
     }
    return 0;
}
