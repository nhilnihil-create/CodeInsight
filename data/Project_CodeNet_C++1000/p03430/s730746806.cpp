#include <bits/stdc++.h>
using namespace std;

string S;
int K;

int main()
{
    cin >> S >> K;
    int L = S.size();
    vector<vector<vector<int> > > dp(L, vector<vector<int> >(L, vector<int>(K+1, 1)));

    // 1文字 dp[i][i][k]は全部1
    
    // 2文字 dp[i][i+1][k]埋め
    for (int i=0; i<L-1; i++)
    {
        dp[i][i+1] = vector<int>(K+1, 2);
        if (S[i] != S[i+1]) dp[i][i+1][0] = 1;
    }
    for (int l=3; l<=L; l++)
    {
        for (int i=0; i<=L-l; i++)
        {
            if (S[i] == S[i+l-1])
            {
                for (int k=0; k<=K; k++) dp[i][i+l-1][k] = dp[i+1][i+l-2][k] + 2;
            }
            else
            {
                for (int k=0; k<=K; k++)
                {
                    int tmpmax = max(dp[i][i+l-2][k], dp[i+1][i+l-1][k]);
                    if (k>0) tmpmax = max(tmpmax, dp[i+1][i+l-2][k-1]+2);
                    dp[i][i+l-1][k] = tmpmax;
                }                
            }
        }
    }
    cout << dp[0].back().back() << endl;
    return 0;
}