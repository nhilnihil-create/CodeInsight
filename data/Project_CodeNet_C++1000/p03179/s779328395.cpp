#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;
    S = "00" + S;

    int dp[N+1][N+1];
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i = 2; i <= N; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j <= i; j++)
        {
            if(S[i] == '<') dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][i-1] + (1000000007 - dp[i-1][j-1])) % 1000000007;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
        }
    }
    cout << dp[N][N] << '\n';
    return 0;
}