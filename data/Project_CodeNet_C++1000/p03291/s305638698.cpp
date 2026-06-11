#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll MOD = 1e9 + 7;
    vector<vector<ll>> dp(S.size() + 1, vector<ll>(4, 0));
    dp.at(S.size()).at(3) = 1;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        ll keisuu = (S.at(i) == '?') ? 3 : 1;
        dp.at(i).at(3) = (dp.at(i + 1).at(3) * keisuu) % MOD;
        vector<char> target = {'A', 'B', 'C'};
        for (int j = 0; j < 3; j++)
        {
            dp.at(i).at(j) = dp.at(i + 1).at(j) * keisuu;
            if (S.at(i) == '?' || S.at(i) == target.at(j))
            {
                dp.at(i).at(j) += dp.at(i + 1).at(j + 1);
            }
            dp.at(i).at(j) = dp.at(i).at(j) % MOD;
        }
    }
    cout << dp.at(0).at(0) << endl;
    return 0;
}
