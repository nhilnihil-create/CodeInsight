#include<cstdio>
#include<algorithm>
int n,flag,x[101],h[101],y[101],re_x,re_y,re_h;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&x[i],&y[i],&h[i]); 
        if(h[i]!=0)
		flag=i;
    }
    for(int j=0;j<=100;++j)
      for(int k=0;k<=100;++k)
        {
            re_x=j;
			re_y=k;
            re_h=h[flag]+abs(x[flag]-re_x)+abs(y[flag]-re_y);
            
            for(int i=1;i<=n;++i)
            {
                if(h[i]!=std::max(re_h-std::abs(x[i]-re_x)-std::abs(y[i]-re_y),0))
				break;
				
                if(i==n)
                {
                    printf("%d %d %d",re_x,re_y,re_h);
                    return 0;
                }
            }
        }
}