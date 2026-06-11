
# include <bits/stdc++.h>
# define A first
# define B second
# define PII pair<int,int>
using namespace std;
const int maxn = 1<<18;
int a[maxn+3];
PII imax[maxn];
void fun(int x, PII &y)
{
    if(x == y.A || x == y.B) return;
    if(a[x] > a[y.A]) y.B = y.A,y.A = x;
    else if(a[x] > a[y.B]) y.B=x;
}
int main()
{
    int N, n, ans=0;
    scanf("%d",&n);
    N = 1<<n;
    a[N] = 0;
    for(int i=0; i<N; ++i) scanf("%d",&a[i]), imax[i].A=i, imax[i].B=N;
    for(int i=1; i<N; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(i&(1<<j))
            {
                int k=i^(1<<j);
                fun(imax[k].A, imax[i]);
                fun(imax[k].B, imax[i]);
            }
        }
    }
    for(int i=1; i<N; ++i)
    {
        ans = max(ans, a[imax[i].A]+a[imax[i].B]);
        printf("%d\n",ans);
    }
    return 0;
}
