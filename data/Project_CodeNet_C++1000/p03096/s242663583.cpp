// ConsoleApplication12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

long long c[200005];
long long dp[2];
long long save[200005];

int main()
{
    int n;
    cin >> n;
    int now = -1;
    for (int i = 0; i != n; i++)
    {
        cin >> c[i];
        if (c[i] == now)
        {
            i--; n--;
        }
        now = c[i];
    }
    dp[0] = 1;
    save[c[0]] = 1;
    for (int i = 1; i != n; i++)
    {
        dp[i & 1] = (dp[!(i & 1)] + save[c[i]]) % 1000000007;
        save[c[i]] += dp[!(i & 1)];
        save[c[i]] %= 1000000007;
    }
    cout << dp[!(n&1)];
}

