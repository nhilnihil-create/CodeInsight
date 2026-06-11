#include<bits/stdc++.h>
using namespace std;
int m[100];
int main()
{  int a,b,k;
    scanf("%d%d%d",&a,&b,&k);

    int z=1;
    if(a>b) swap(a,b);
    for(int i=a;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
         m[z++]=i;

    }

    printf("%d\n",m[k]);

}
