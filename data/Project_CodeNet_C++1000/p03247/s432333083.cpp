#include<cstdio>
#include<cmath>
using namespace std;
long long x[1001],y[1001],sol[50];
char s[50];
long long putere2(long long x)
{
    if(x==0)
        return 0;
    long long i=1;
    while(i-1+i<=x-1)
    {
        i*=2;
    }
    return i-1+i;
}

int main()
{
    //freopen("f.in","r",stdin);
    //freopen("f.out","w",stdout);
    long long n,i,j;
    long long ok=1,val;
    scanf("%lld",&n);
    scanf("%lld%lld",&x[1],&y[1]);
    val=((long long)fabs(x[1])+(long long)fabs(y[1]))%2;
    for(i=2; i<=n; ++i)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        if(((long long)fabs(x[i])+(long long)fabs(y[i]))%2!=val)
        {
            ok=0;
            break;
        }
    }
    if(!ok)
        printf("-1\n");
    else
    {
        long long start=0;
        long long maxim=0,nrsol=0;
        if((x[1]+y[1])%2==0)
        {
            start=1;
            for(i=1; i<=n; ++i)
            {
                x[i]--;
            }
        }
        for(i=1; i<=n; ++i)
        {
            if(maxim<putere2((long long)fabs(x[i]))+(long long)fabs(y[i]))
                maxim=putere2((long long)fabs(x[i])+(long long)fabs(y[i]));
        }
        if(start)
            sol[++nrsol]=1;
        long long val=((maxim-1)/2)+1;
        while(val)
        {
            sol[++nrsol]=val;
            val/=2;
        }
        printf("%lld\n",nrsol);
        for(i=1;i<=nrsol;++i)
        {
            printf("%lld ",sol[i]);
        }
        printf("\n");
        long long poz;
        for(i=1; i<=n; ++i)
        {
            poz=start+1;
            while(sol[poz])
            {
                if((long long)fabs(x[i]-sol[poz])+(long long)fabs(y[i])<=sol[poz]-1)
                {
                    s[poz]='R';
                    x[i]-=sol[poz];
                }
                else
                {
                    if((long long)fabs(x[i]+sol[poz])+(long long)fabs(y[i])<=sol[poz]-1)
                    {
                        s[poz]='L';
                        x[i]+=sol[poz];
                    }
                    else
                    {
                        if((long long)fabs(x[i])+(long long)fabs(y[i]-sol[poz])<=sol[poz]-1)
                        {
                            s[poz]='U';
                            y[i]-=sol[poz];
                        }
                        else
                        {
                            if((long long)fabs(x[i])+(long long)fabs(y[i]+sol[poz])<=sol[poz]-1)
                            {
                                s[poz]='D';
                                y[i]+=sol[poz];
                            }
                        }
                    }
                }
                poz++;
            }
            if(start)
                printf("R");
            for(j=start+1;j<=nrsol;++j)
            {
                printf("%c",s[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
