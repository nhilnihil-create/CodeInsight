#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const ll inf = 1e18;
const int mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

const int N = 1<<22;

int mat[20][20];
ll val[1<<17];
ll dp[1<<17];

int main()
{
    int i, j, k;

    int n;
    cin >> n;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];

    memset(val, 0, sizeof(val));
    memset(dp, 0, sizeof(dp));

    for(i = 0; i < (1<<n); i++)
    {
        for(j = 0; j < n; j++)
            if( (1<<j)&i )
                for(k = j+1; k < n; k++)
                    if( (1<<k)&i )
                        val[i] += mat[j][k];
    }

    //for(i = 0; i < (1<<n); i++)
    //    cout << val[i] << '\n';

    for(i = 0; i < (1<<n); i++)
    {
        //not yet selected. Let's form another group with it.
        vector<int> pos;
        for(j = 0; j < n; j++)
            if(!( (1<<j)&i ))
                pos.pb(j);
        
        int tam = (int)pos.size();
        for(j = 0; j < (1<<tam); j++)
        {
            int mask = 0;
            for(k = 0; k < tam; k++)
                if( (1<<k)&j )
                    mask |= (1<<pos[k]);
        
            dp[mask|i] = max(dp[mask|i], dp[i] + val[mask]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';

}


