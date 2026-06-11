#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 305
using namespace std;
int n;
bool vis[M][M][M];
double dp[M][M][M];

double dfs(int x,int y,int z) {
    if (x<0 || y<0 || z<0) return 0.0;
    if (x==0 && y==0 && z==0) return 0.0;
    if (vis[x][y][z]) return dp[x][y][z];
    vis[x][y][z] = true;
    double &res = dp[x][y][z];
    
    double f = (double)(n-x-y-z) / n;
    res = dfs(x-1, y, z)*((double)x/n) +
        dfs(x+1, y-1, z)*((double)y/n) +
        dfs(x, y+1, z-1)*((double)z/n) +
        1.0;
    res /= (1.0 - f);
    return res;
}
int main()
{
    int c[4] = {0, 0, 0, 0};
    scanf("%d", &n);
    REP(i,1,n) {
        int x;
        scanf("%d", &x);
        c[x]++;
    }

    printf("%.10f\n", dfs(c[1], c[2], c[3]));
    return 0;
}
