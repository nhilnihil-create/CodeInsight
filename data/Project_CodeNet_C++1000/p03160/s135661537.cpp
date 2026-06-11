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
    ll n, a[SZ], dp[SZ];
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = 0;
    if(n > 1) dp[2] = abs(a[1] - a[2]);
    //if(n > 2) dp[3] = abs(a[2] - a[3]);
    for(int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n] << endl;
}

int main()
{
    #ifdef FILEIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tc;

    //cin >> tc;
    //while(tc--)
    {
        solve();
    }

    return 0;
}


