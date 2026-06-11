#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 310;

bool vis[N][N][N];
int n,c1,c2,c3;
double mem[N][N][N];

double dp(int i,int j,int k)
{
    if( i < 0 || j < 0 || k < 0 )
        return 0.0;

    if( !i && !j && !k )
        return 0.0;

    double &ret = mem[i][j][k];
    if( vis[i][j][k] )
        return ret;
    vis[i][j][k] = 1;

    return ret = ( 1.0 + (1.0*i)/n*dp(i-1,j,k) + (1.0*j)/n*dp(i+1,j-1,k) + (1.0*k)/n*dp(i,j+1,k-1) ) / ( 1.0 - (1.0*n-i-j-k)/n);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if( x == 1 )
            c1++;
        if( x == 2 )
            c2++;
        if( x == 3 )
            c3++;
    }

    printf("%.9f\n",dp(c1,c2,c3));
}
