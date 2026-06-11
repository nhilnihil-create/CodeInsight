#include <iostream>
#include <string>

using namespace std;

const int NMAX = 3000;
const int MOD = 1e9 + 7;

int N;
string s;

int dp[NMAX + 5][NMAX + 5]; ///dp[i][j] -> nr de permutari de lungime i cu ultimul element j
int sp[NMAX + 5][NMAX + 5]; ///sp[i][j] -> suma dp[i][1] + dp[i][2] + ... + dp[i][j]

int main()
{
    cin >> N >> s;

    dp[1][1] = sp[1][1] = 1;

    for(int l = 2; l <= N; l++)
        {
            for(int c = 1; c <= l; c++)
                {
                    if(s[l - 2] == '<')
                        dp[l][c] = sp[l - 1][c - 1];
                    else
                        dp[l][c] = (sp[l - 1][l - 1] - sp[l - 1][c - 1] + MOD) % MOD;
                }

            ///sp
            for(int c = 1; c <= l; c++)
                sp[l][c] = (sp[l][c - 1] + dp[l][c]) % MOD;
        }

    cout << sp[N][N] << '\n';

    return 0;
}
