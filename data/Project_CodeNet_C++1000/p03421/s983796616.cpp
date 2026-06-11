#include <cstdio>
#include <vector>
typedef long long ll;

int n,A,B;
std::vector<int> a[300005];

int main()
{
    scanf("%d%d%d",&n,&A,&B);
    if(A+B-1<=n&&n<=(ll)A*B)
    {
        for(int i=B;i>=1;--i)a[1].push_back(i);
        // n-B -> A-1
        int Rem=n-B,Nv=B+1;
        for(int i=2;i<=A;++i)
        {
            int Cnt=Rem/(A-1)+(i-2<Rem%(A-1));
            for(int j=Nv+Cnt-1;j>=Nv;--j)a[i].push_back(j);
            Nv+=Cnt;
        }
        for(int i=1,j=0;i<=A;++i)
            for(auto k:a[i])
                printf("%d%c",k," \n"[++j==n]);
    }
    else puts("-1");
    return 0;
}