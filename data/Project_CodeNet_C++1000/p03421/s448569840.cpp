#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a>n || b>n || a+b>n+1)
    {
        puts("-1");
    }
    else if(a>=b)
    {
        int c = (n+b-1)/b, d=0;
        if(c>a) puts("-1");
        else
        {
            while(c+d<a)
            {
                d++;
                c = (n-d+b-1)/b;
            }
            int rr = n-d, l=0;
            while(l<rr)
            {
                int r = min(l+b,rr);
                for(int i=r;i>l;i--) printf("%d ",i);
                l = r;
            }
            for(int i=rr+1;i<=n;i++) printf("%d ",i);
        }
    }
    else if(b>a)
    {
        int c = (n+a-1)/a, d=0;
        if(c>b) puts("-1");
        else
        {
            while(c+d<b)
            {
                d++;
                c = (n-d+a-1)/a;
            }
            int ll = d, r=n;
            while(r>ll)
            {
                int l = max(r-a+1,ll+1);
                for(int i=l;i<=r;i++) printf("%d ",i);
                r = l-1;
            }
            for(int i=ll;i;i--) printf("%d ",i);
        }
    }
}
