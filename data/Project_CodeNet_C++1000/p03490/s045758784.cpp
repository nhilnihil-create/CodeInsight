#include<bits/stdc++.h>
using namespace std;
const int N=8005,low=8000;
char s[N];
int x,y,n;
bitset<N*2>bx,by;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d%d",&x,&y);
    bx[0+low]=1;by[0+low]=1;
    bool flag=true;
    int t=0,st=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='F') t++;
    else
    {
        if(flag)
            bx<<=t,flag=false;
        else
        {
            if(st) by=(by<<t)|(by>>t);
            else bx=(bx<<t)|(bx>>t);
        }
        st^=1;
        t=0;
    }
    if(flag)
        bx<<=t,flag=false;
    else
    {
        if(st) by=(by<<t)|(by>>t);
        else bx=(bx<<t)|(bx>>t);
    }
    if(bx[x+low]&&by[y+low]) printf("Yes\n");
    else printf("No\n");
}
