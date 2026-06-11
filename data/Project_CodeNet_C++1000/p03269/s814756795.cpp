#include <bits/stdc++.h>
using namespace std;

int l;
int x,y;
int tmp[25],sl=0;

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    scanf("%d ",&l);

    int k=log2(l);

    while(l>0)
    {
        if(l%2==1)
            tmp[++sl]=x;
        x++;
        l/=2;
    }

    printf("%d %d\n",k+1,2*k-1+sl);

    for(int i=1; i<=k; ++i)
    {
        printf("%d %d %d\n",i,i+1,0);
        printf("%d %d %d\n",i,i+1,1<<(i-1));
    }

    y=1<<k;

    for(int i=1; i<sl; ++i)
    {
        printf("%d %d %d\n",tmp[i]+1,k+1,y);
        y+=1<<tmp[i];
    }
}
