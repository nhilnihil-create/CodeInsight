#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int dp[110000];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 110000; i++)dp[i] = i;

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 6; j <= n; j *= 6)
        {
            if(i + j > 110000)break;
            chmin(dp[i + j], dp[i] + 1);
        }
        for (int j = 9; j <= n; j *= 9)
        {
            if(i + j > 110000)break;
            chmin(dp[i + j], dp[i] + 1);
        }
    }
    
    cout << dp[n] << endl;
}