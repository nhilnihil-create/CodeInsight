#include<bits/stdc++.h>
using namespace std;

int a[10];
int ans;

int main()
{
    for(int i=1;i<=4;i++)
    {
        scanf("%1d",&a[i]);
        if(a[i]==2) ans++;
    }
    printf("%d",ans);
    return 0;
}