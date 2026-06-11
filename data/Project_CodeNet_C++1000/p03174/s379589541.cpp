#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const int mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

const int N = 1<<22;

int n;
int mat[25][25];

ll dp[22][N];

ll solve(int a, int b)
{

    if( (b > (1<<n)-1) || a > 21)
        return 0;

    //cout << a << ' ' << b << '\n';

    ll &h = dp[a][b];
    if( b == ((1<<n) -1) && a == n )
        return h = 1;
    
    if(h != -1)
        return h;

    int i, j;

    h = 0;
    for(i = 0; i < n; i++)
        if(mat[a][i] == 1 && ((1<<i) & b) == 0)
            h = (h + solve(a+1, (1<<i) | b))%mod;

    return h;
}

int main()
{
    int i, j;

    memset(mat, 0, sizeof(mat));
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << solve(0, 0) << '\n';
}