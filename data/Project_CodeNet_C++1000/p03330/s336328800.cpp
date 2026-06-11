#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;
    vector<vector<ll>> costs(C + 1, vector<ll>(C + 1)); //at(from).at(to)
    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> costs.at(i).at(j);
        }
    }
    vector<vector<ll>> colorCounts(3, vector<ll>(C + 1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ll color;
            cin >> color;
            colorCounts.at((i + j) % 3).at(color)++;
        }
    }
    ll answer = 1e12;
    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (int k = 1; k <= C; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }
                ll tempAnswer = 0;
                for (int n = 1; n <= C; n++)
                {
                    tempAnswer += colorCounts.at(0).at(n) * costs.at(n).at(i);
                    tempAnswer += colorCounts.at(1).at(n) * costs.at(n).at(j);
                    tempAnswer += colorCounts.at(2).at(n) * costs.at(n).at(k);
                }
                answer = min(answer, tempAnswer);
            }
        }
    }
    cout << answer << endl;
    return 0;
}