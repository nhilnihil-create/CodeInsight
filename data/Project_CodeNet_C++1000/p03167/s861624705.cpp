#include <bits/stdc++.h>
#define inf 1000000007
#define N 1007
using namespace std;

int h, w;
char path[N][N];
long long mem[N][N];

long long dp(int i, int j)
{
    if(i == (h - 1) && j == (w - 1))
        return 1;
    if(mem[i][j] != -1)
        return mem[i][j];
    long long ans = 0;
    if((j + 1) != w && path[i][j + 1] != '#')
        ans = ((ans % inf) + (dp(i, j + 1) % inf)) % inf;
    if((i + 1) != h && path[i + 1][j] != '#')
        ans = ((ans % inf) + (dp(i + 1, j) % inf)) % inf;
    mem[i][j] = ans;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> h >> w;
    for(int i = 0;i < h;i++)
        for(int j = 0;j < w;j++)
            cin >> path[i][j];
    memset(mem, -1, sizeof(mem));
    cout << dp(0, 0) << endl;
    return 0;
}