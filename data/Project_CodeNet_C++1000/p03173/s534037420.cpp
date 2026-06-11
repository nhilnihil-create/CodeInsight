#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "main"
#define ll long long
#define maxn 405
#define oo 100000000000000

using namespace std;

int n,a[maxn];
ll res[maxn][maxn],b[maxn];
bool xd[maxn][maxn];

ll sol(int x,int y)
{
    if(x==y)
    {
        return 0;
    }
    if(xd[x][y]!=0)
    {
        return res[x][y];
    }
    xd[x][y]=1;
    res[x][y]=oo;
    f(i,x,y-1)
    {
        res[x][y]=min(res[x][y],sol(x,i)+sol(i+1,y)+b[y]-b[x-1]);
    }
    return res[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);

    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    cout<<sol(1,n);




}
