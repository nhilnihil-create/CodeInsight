#include <bits/stdc++.h>
using namespace std;
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE;
    SetConsoleTextAttribute(hConsole, 7);
    cerr << '\n';
#endif
}
#else
#define print(x) 0
#endif
typedef long long ll;
typedef unsigned long long ull;
const ll INFLL = 2 * (ll)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
const double PI = atan(1) * 4;
const double EPS = 1e-12;
const int SEED = 1e3 + 7;

const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const int NMAX = 300 + 5;

string s;
int k;
int dp[NMAX][NMAX][NMAX], trecut[NMAX][NMAX][NMAX];

void solve(int l, int r, int x)
{
    if(trecut[l][r][x]) return;
    if(l == r)
    {
        dp[l][r][x] = 1;
        trecut[l][r][x] = 1;
        return;
    }
    if(l > r)
    {
        dp[l][r][x] = 0;
        trecut[l][r][x] = 1;
        return;
    }

    if(s[l] == s[r])
    {
        if(!trecut[l + 1][r - 1][x]) solve(l + 1, r - 1, x);
        dp[l][r][x] = 2 + dp[l + 1][r - 1][x];
    }
    else
    {
        if(x - 1 >= 0)
        {
            if(!trecut[l + 1][r - 1][x - 1])
                solve(l + 1, r - 1, x - 1);
            dp[l][r][x] = 2 + dp[l + 1][r - 1][x - 1];
        }

        if(!trecut[l + 1][r][x]) solve(l + 1, r, x);
        if(!trecut[l][r - 1][x]) solve(l, r - 1, x);
        dp[l][r][x] = max(dp[l][r][x], max(dp[l + 1][r][x], dp[l][r - 1][x]));

    }
    trecut[l][r][x] = 1;
}

int main()
{
    FASTIO;
    cin >> s >> k;
    int n = s.size();
    solve(0, n - 1, k);
    int sol = 1;
    for0(i, n)
    for0(j, n)
    for0(K, k + 1)
    {
        if(!trecut[i][j][K]) solve(i, j, K);
        sol = max(sol, dp[i][j][K]);
    }

    cout << sol;
    return 0;
}
