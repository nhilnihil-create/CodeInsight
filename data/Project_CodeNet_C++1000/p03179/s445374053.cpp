#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
#define turbo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define qi queue<int>
#define ld long double

using namespace std;

/*---------------------------------------------------------///CODE///---------------------------------------------------------*/

const int N = 3e3;
const int MOD = 1e9 + 7;
int dp[N + 10][N + 10];
int pref[N + 10][N + 10];

int main()
{
    turbo

    int n; cin >> n;

    string s; cin >> s;

    dp[1][1] = 1;
    pref[1][1] = 1;
    for(int i = 2; i <= s.size() + 1; i++)
    {
        for(int j = 1; j <= i; j++)
            (dp[i][j] += (s[i - 2] == '<' ? pref[i - 1][j - 1] : pref[i - 1][i - 1] - pref[i - 1][j - 1] + MOD)) %= MOD;

        for(int j = 1; j <= i; j++)
            pref[i][j] = (pref[i][j - 1] + dp[i][j]) % MOD;
    }

    int ans = 0;

    for(int i = 1; i <= s.size() + 1; i++)
        (ans += dp[s.size() + 1][i]) %= MOD;

    return cout << ans, 0;
}