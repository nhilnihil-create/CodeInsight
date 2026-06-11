#include<bits/stdc++.h>
using namespace std;


int ans[300050];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a+b>n+1)
        puts("-1");
    else
    {
        int f=0;
        if(a<b)
            swap(a,b),f=1;

        int c=(n+b-1)/b;
        if(c>a)
            puts("-1");
        else
        {
            int x=-1,y;
            for(int i=0;i<=n;i++)
                if(i+((n-i+b-1)/b)==a)
                {
                    x=i;
                    break;
                }
            int now=n,pos=n-1;
            for(int i=0;i<x;i++)
                ans[pos--]=now--;
            int p=1,pos2=b-1,cnt=0;
            while(p<=now)
            {
                ans[pos2--]=p++;
                cnt++;
                if(cnt%b==0)
                {
                    pos2+=b+min(b,now-p+1);
                }
            }
            if(f)
            {
                for(int i=0;i<n/2;i++)
                    swap(ans[i],ans[n-i-1]);
            }
            printf("%d",ans[0]);
            for(int i=1;i<n;i++)
                printf(" %d",ans[i]);
            puts("");
        }
    }
	return 0;
}

