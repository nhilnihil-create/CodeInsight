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
    vector<int> maxByMatches(8, -1);
    vector<int> numAndMatches{-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 0; i < M; i++)
    {
        int A;
        cin >> A;
        maxByMatches.at(numAndMatches.at(A)) = max(maxByMatches.at(numAndMatches.at(A)), A);
    }
    vector<int> dp(N + 7, -1);
    dp.at(0) = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp.at(i) == -1)
        {
            continue;
        }
        for (int j = 2; j <= 7; j++)
        {
            if (maxByMatches.at(j) == -1)
            {
                continue;
            }
            dp.at(i + j) = max(dp.at(i + j), dp.at(i) + 1);
        }
    }
    vector<int> answers;
    int currentKeta = dp.at(N);
    int remainMatches = N;
    for (int i = 0; i < N; i++)
    {
        int maxNum = 0;
        int matchNum;
        for (int j = 2; j <= 7; j++)
        {
            if (remainMatches - j >= 0 && dp.at(remainMatches - j) == currentKeta - 1 && maxNum < maxByMatches.at(j))
            {
                matchNum = j;
                maxNum = maxByMatches.at(j);
            }
        }
        answers.push_back(maxNum);
        remainMatches -= matchNum;
        if (remainMatches == 0)
        {
            break;
        }
        currentKeta--;
    }
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers.at(i);
    }
    cout << endl;
    return 0;
}
