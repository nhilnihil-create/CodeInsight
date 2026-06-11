#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 2e5 + 50, INF = 1e15, MOD = 1e9 + 7;
ll N, hts[max_N], beauty[max_N], DP[max_N];

struct custom_comparator
{
    bool operator() (const ll &idx1, const ll &idx2) const
    {
        return hts[idx1] < hts[idx2];
    }
};

ll solve()
{
    set<ll, custom_comparator> meaning;
    ll res = 0;
    DP[0] = beauty[0];
    meaning.insert(0);
    for (int i = 1; i < N; ++i)
    {
        DP[i] = beauty[i];
        auto it = meaning.upper_bound(i);
        if (it != meaning.begin())
        {
            it = prev(it);
            DP[i] = DP[*it] + beauty[i];
        }
        meaning.insert(i);
        it = meaning.upper_bound(i);
        while (it != meaning.end() && DP[*it] <= DP[i])
        {
            auto temp = next(it);
            meaning.erase(it);
            it = temp;
        }
    }
    res = *max_element(DP, DP + N);
    return res;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> hts[i];
    for (int i = 0; i < N; ++i)
        cin >> beauty[i];
    cout << solve() << "\n";
    return 0;
}