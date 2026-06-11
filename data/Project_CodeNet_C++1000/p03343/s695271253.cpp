#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> nums(N);
    vector<pll> sortNums;
    for (int i = 0; i < N; i++)
    {
        ll A;
        cin >> A;
        nums.at(i) = A;
    }
    ll answer = 1e12;
    for (int i = 0; i < N; i++)
    {
        ll minValue = nums.at(i);
        vector<vector<ll>> dividedNums;
        dividedNums.push_back(vector<ll>());
        for (int j = 0; j < N; j++)
        {
            if (nums.at(j) < minValue)
            {
                if (dividedNums.back().size() > 0)
                {
                    dividedNums.push_back(vector<ll>());
                }
            }
            else
            {
                dividedNums.back().push_back(nums.at(j));
            }
        }
        vector<ll> kouhoNums;
        for (auto dividedNum : dividedNums)
        {
            if (dividedNum.size() < K)
            {
                continue;
            }
            sort(dividedNum.begin(), dividedNum.end());
            for (int j = 0; j < min(Q, (ll)dividedNum.size() - K + 1); j++)
            {
                kouhoNums.push_back(dividedNum.at(j));
            }
        }
        if (kouhoNums.size() < Q)
        {
            continue;
        }
        sort(kouhoNums.begin(), kouhoNums.end());
        answer = min(answer, kouhoNums.at(Q - 1) - kouhoNums.at(0));
    }
    cout << answer << endl;
    return 0;
}
