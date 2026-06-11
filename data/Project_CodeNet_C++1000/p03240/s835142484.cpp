#include<cstdio>
#include<algorithm>
int n,a,b,u,x[101],h[101],y[101],cx,cy,H;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&x[i],&y[i],&h[i]); 
        if(h[i]!=0)u=i;
    }
    for(int xi=0;xi<=100;++xi)
      for(int yi=0;yi<=100;++yi)
        {
            cx=xi,cy=yi;
            H=h[u]+abs(x[u]-cx)+abs(y[u]-cy);
            for(int i=1;i<=n;++i)
            {
                if(h[i]!=std::max(H-std::abs(x[i]-cx)-std::abs(y[i]-cy),0))break;
                if(i==n)
                {
                    printf("%d %d %d",cx,cy,H);
                    return 0;
                }
            }
        }
}