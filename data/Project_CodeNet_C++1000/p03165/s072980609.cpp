#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    int dp[s.size() + 1][t.size() + 1];
    memset(dp, 0, sizeof(dp));

    for (auto i=0; i<s.size(); ++i)
    {
        for (int k = 0; k<t.size(); ++k)
        {
            // Sのi番目とTのj番目が同じ文字なら共通部分列
            if (s[i] == t[k])
                dp[i + 1][k + 1] = std::max(dp[i+1][k+1], dp[i][k] + 1);
            // 一致してなかったときはSのi文字目とTのj文字目までのLCSで大きい方
            else
            {
                dp[i + 1][k + 1] = std::max(dp[i+1][k+1], dp[i+1][k]);
                dp[i + 1][k + 1] = std::max(dp[i+1][k+1], dp[i][k+1]);
            }
        }
    }

    std::string result;
    int i = s.size();
    int j = t.size();
    while (0 < i && 0 < j)
    {
        // 一致してないので dp[i][j+1] のLCSで更新していた場合
        if (dp[i][j] == dp[i-1][j])
            i--;
        // 一致してないので dp[i+1][j] のLCSで更新していた場合
        else if (dp[i][j] == dp[i][j-1])
            j--;
        // s[i+1], t[j+1] が一致してた場合
        else
        {
            result = s[i-1] + result;
            i--;
            j--;
        }
    }
    std::cout << result << std::endl;
}
