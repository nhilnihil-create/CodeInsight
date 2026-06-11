#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<limits>
#include<stack>
#include<array>
#include<stdio.h>
#include<cstring>

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;

int INF = 1000000009; //std::numeric_limits<int>::max();
ll LLINF = 1e15;
int NINF = std::numeric_limits<int>::min();
int MOD = 1e9+7;

int col[] = {1,0,-1,0,1,1,-1,-1};
int row[] = {0,1,0,-1,1,-1,1,-1};

//knight moves
int cc[] = {1,2,2,1,-1,-1,-2,-2};
int rr[] = {-2,-1,1,2,-2,2,1,-1};


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;

    vll cumsum(n+1,0);
    vll slimes(n+1);

    cumsum[0] = 0;

    for(int i = 1 ; i <= n ; ++i)
        {
            cin >> slimes[i];
            cumsum[i] = cumsum[i-1]+slimes[i];
        }

    vvll dp(401,vll(401,0));

    for(int j = 2; j <= n ; ++j)
    {
        for(int i = 1; i <= n-j+1 ; ++i)
        {
            int clmn = i+j-1;

            ll rangeDiff = cumsum[clmn]-cumsum[i-1];

            dp[i][clmn] = 1e18;
            for(int k = i ; k < clmn; ++k)
            dp[i][clmn] = min(dp[i][clmn], rangeDiff + dp[i][k] + dp[k+1][clmn]);
        }
    }

    /*for(int i = 0 ; i <n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
            cout << dp[i][j] << "   ";
        cout << endl;
    }*/


    cout << dp[1][n];

    return 0;
}
