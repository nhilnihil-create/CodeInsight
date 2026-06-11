#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    vector<int> dp(100001, MOD);
    dp[0] = 0;
    vector<int> list{1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049};
    sort(list.begin(), list.end());
    int N;
    cin >> N;
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (i - list[j] < 0)
                break;
            else
                dp[i] = min(dp[i], dp[i - list[j]] + 1);
        }
    }
    cout << dp[N];
}