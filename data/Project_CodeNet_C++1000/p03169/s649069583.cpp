#include<bits/stdc++.h>
#define fori(x,a,b) for (int x=a;x<=b;x++)
using namespace std;
int n,x;
int cnt[5];
double f[310][310][310];

double dp(int a,int b,int c)
{
    if (a+b+c==0) return 0.0;
    if (f[a][b][c] > -0.5) return f[a][b][c];
    double tg = (double) n/(a+b+c);
    double r=0;
    if (a)
    {
        r+=( dp(a-1,b,c) + tg)*a/(a+b+c);
    }
    if (b)
    {
        r+=( dp(a+1,b-1,c) + tg)*b/(a+b+c);
    }
    if (c)
    {
        r+=( dp(a,b+1,c-1) + tg)*c/(a+b+c);
    }
    return f[a][b][c] = r;
}
int main()
{
    cin>>n;
    fori(i,1,n)
    {
       cin>>x;
       cnt[x]++;
    }
    fori(i,0,n)
    fori(j,0,n)
    fori(k,0,n) f[i][j][k] = -1;
    double kq = dp(cnt[1],cnt[2],cnt[3]);
    cout<<fixed<<setprecision(14)<<kq;
}
