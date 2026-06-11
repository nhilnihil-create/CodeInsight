#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    //1がplus、0がminusとみなした場合の絶対値
    vector<vector<vector<vector<ll>>>> plusMinusAbs(2, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(0))));
    for (int i = 0; i < N; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        plusMinusAbs.at(1).at(1).at(1).push_back(x + y + z);
        plusMinusAbs.at(1).at(1).at(0).push_back(x + y - z);
        plusMinusAbs.at(1).at(0).at(1).push_back(x - y + z);
        plusMinusAbs.at(1).at(0).at(0).push_back(x - y - z);
        plusMinusAbs.at(0).at(1).at(1).push_back(-1 * x + y + z);
        plusMinusAbs.at(0).at(1).at(0).push_back(-1 * x + y - z);
        plusMinusAbs.at(0).at(0).at(1).push_back(-1 * x - y + z);
        plusMinusAbs.at(0).at(0).at(0).push_back(-1 * x - y - z);
    }
    ll answer = 0;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                sort(plusMinusAbs.at(i).at(j).at(k).begin(), plusMinusAbs.at(i).at(j).at(k).end(), greater<ll>());
                ll tmpAnswer = 0;
                for (int l = 0; l < M; l++)
                {
                    tmpAnswer += plusMinusAbs.at(i).at(j).at(k).at(l);
                }
                answer = max(answer, tmpAnswer);
            }
        }
    }
    cout << answer << endl;
    return 0;
}