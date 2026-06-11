///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int mx = 1e5+123;
int h[mx], n, k;
int dp[mx];

int solve ( int i )
{
    if ( i == n ) return 0;
    if ( dp[i] != -1 ) return dp[i];

    int ret = 2e9;

    for ( int j = 1; j <= k; j++ ) {
        if ( i+j <= n ) ret = min ( ret,  abs ( h[i] - h[i+j] ) + solve ( i+j ) );
    }

    return dp[i] = ret;
}


int main()
{

    cin >> n >> k;
    for ( int i = 1; i <= n; i++ ) cin >> h[i];

    memset ( dp, -1, sizeof ( dp ) );
    cout << solve ( 1 ) << endl;

    return 0;
}