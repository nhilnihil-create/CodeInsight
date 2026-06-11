#include <bits/stdc++.h>

using namespace std;
int xz[200005];
int main()
{
    int h,w,m;
    scanf("%d%d%d",&h,&w,&m);
    int j=1;while(j<=h)
    {
        xz[j]=w+1;
        j++;
    }
    int i=1;while(i<=m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        xz[x]=min(xz[x],y);
        i++;
    }
    int r=1;
    i=1;while(i<=h)
    {
        if(i==h||xz[i+1]<=r)
        {
            cout<<i<<endl;
            break;
        }
        r++;
        if(xz[i+1]==r) r--;
        i++;
    }
    return 0;
}
