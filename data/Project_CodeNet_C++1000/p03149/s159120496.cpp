#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
int main()
{
    int k;
    for(int i=1;i<=4;i++)
    {
        scanf("%d",&k);
        if(k==1)a=true;
        else if(k==9)b=true;
        else if(k==7)c=true;
        else if(k==4)d=true;
    }
    if(a&&b&&c&&d)printf("YES");
    else printf("NO");
}