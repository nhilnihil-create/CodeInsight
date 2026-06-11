#include<bits/stdc++.h>
using namespace std;

string S;
int dp[1 << 26];
int N;
int INF = 100000000;

int main()
{
    cin >> S;

    int N = S.size();

    for(int i = 1; i < (1 << 26); i++)dp[i] = INF;

    int now = 0;
    for(int i = 0; i < N; i++)
    {
        now ^= (1 << (S[i] - 'a'));
        int tmp = dp[now] + 1;
        for(int j = 0; j < 26; j++)tmp = min(tmp, dp[now ^ (1 << j)] + 1);
        dp[now] = min(dp[now], tmp);
        if(i == N - 1)cout << tmp << endl;
    }

    return 0;
}
