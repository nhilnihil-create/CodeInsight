#include <iostream>
#define SM 30
using namespace std;
long long n,a[SM][SM],F[SM][3000000];
long long Try(long long i,long long Free)
    {
        long long j;
        if (i>n) return 1;
        if (F[i][Free]!=-1) return(F[i][Free]);
        F[i][Free]=0;
        for (j=1;j<=n;++j)
            if ((Free>>(j-1)&1)==0 && a[i][j]==1)
                F[i][Free]=(F[i][Free]+Try(i+1,Free|(1<<(j-1))))%((long long)1e9+7);
        return F[i][Free];
    }
int main()
    {
        //freopen("MATCHING.INP","r",stdin);
        //freopen("MATCHING.OUT","w",stdout);
        long long i,j;
        cin>>n;
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j) cin>>a[i][j];
        for (i=1;i<=n+1;++i)
            for (j=0;j<=3000000;++j) F[i][j]=-1;
        cout<<Try(1,0);
        return 0;
    }
