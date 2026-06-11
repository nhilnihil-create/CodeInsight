//In The Name of ALLAH//

/*      ______     _    _______
       |  ___ \   | |  |  ____/   /\
       | |   \ \  | |  | |       /  \
       | |___/ /  | |  | |___   / /\ \
       |     _/   | |  |  __/  / /__\ \
       | |\ \     | |  | |    / ______ \
       | | \ \    | |  | |   / /      \ \
       |_|  \_\   |_|  |_|  /_/        \_\
*/

#include<bits/stdc++.h>

//#define FILEIO
#define ll long long

using namespace std;

const int SZ = 100005;
const int LIM = 1000000000;
const double EPS = 1e-9;
const int MOD = 100000008;
const int INF = ( 1 << 30 ) - 1;
const double PI = 2 * acos( 0.0 );

template <class T> T MIN(T a, T b) { return (a < b) ? a : b; }
template <class T> T MAX(T a, T b) { return (a > b) ? a : b; }
template <class T> void SWAP(T &a, T &b) { T c; c = a; a = b; b = c; }
template <class T> T GCD(T a, T b) { T c; while(b > 0) { c = a % b; a = b; b = c; } return a; }

bool CMP(int a, int b)
{
    return (a > b);
}

void solve()
{
    ll n, k, a[SZ], dp[SZ];
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i > j) dp[i] = min(dp[i - j] + abs(a[i - j] - a[i]), dp[i]);
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    #ifdef FILEIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    //int tc;

    //cin >> tc;
    //while(tc--)
    {
        solve();
    }

    return 0;
}



