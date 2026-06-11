#include <iostream>
#include <cstring>
using namespace std;
char S[305];
int N, K;
int DP[305][305][305];
int Prev[305][305];
int Next[305][305];
void Read()
{
    cin.getline(S + 1, 305);
    N = strlen(S + 1);
    cin >> K;
}

void Solve()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
            DP[i][i][j] = 1, Next[i][j] = 1, Prev[i][j] = 1;

    }
    for(int i = 1; i < N; i++)
    {
        if(S[i] == S[i + 1])
            DP[i][i + 1][0] = 2;
        else
        {
            DP[i][i + 1][0] = 1;
            DP[i][i + 1][1] = 2;
        }
        for(int j = 1; j <= N; j++)
            DP[i][i + 1][j] = 2, Next[i][j] = 2, Prev[i + 1][j] = 2;
        Next[i][0] = max(Next[i][0], DP[i][i + 1][0]);
        Prev[i + 1][0] = max(Prev[i + 1][0], DP[i][i + 1][0]);
    }
    for(int dist = 3; dist <= N; dist++)
    {
        for(int i = 1; i + dist - 1 <= N; i++)
        {
            int j = i + dist - 1;
            for(int k = 0; k <= N; k++)
            {
                DP[i][j][k] = max(Next[i][k], Prev[j][k]);
                if(S[i] == S[j])
                    DP[i][j][k] = max(DP[i][j][k], DP[i + 1][j - 1][k] + 2);
                else
                    if(k > 0)
                        DP[i][j][k] = max(DP[i][j][k], DP[i + 1][j - 1][k - 1] + 2);
                Prev[j][k] = max(Prev[j][k], DP[i][j][k]);
                Next[i][k] = max(Next[i][k], DP[i][j][k]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= K; i++)
        ans = max(ans, DP[1][N][i]);
    cout << ans << "\n";
}
int main()
{
    Read();
    Solve();
    return 0;
}
