#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n; //Nの各桁の数字を格納するベクター
int dp[100][2][(1 << 3)];

int main()
{
    cin >> N;

    //ベクターnを構成
    for (auto a : N)
    {
        n.push_back(a - '0');
    }
    int l = N.size(); //nの長さ

    dp[0][0][0] = 1;
    for (int i = 1; i < l; i++)
    {
        dp[i][1][0] = 1;
    }
    
    
    for (int i = 0; i < l; i++)
    {
        for (int d = 0; d < 10; d++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < (1 << 3); k++)
                {
                    if (d > n[i] && j == 0)
                    {
                        continue;
                    }
                    if (d != 3 && d != 5 && d != 7)
                    {
                        continue;
                    }
                    int nj = (n[i] > d) ? 1 : j;
                    int nk = k;
                    if (d == 3)
                        nk |= (1 << 2);
                    if (d == 5)
                        nk |= (1 << 1);
                    if (d == 7)
                        nk |= (1 << 0);

                    dp[i + 1][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[l][0][0b111] + dp[l][1][0b111] << endl;

    return 0;
}