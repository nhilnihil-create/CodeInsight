#include <bits/stdc++.h>

using namespace std;

int solve(int K, vector<int> &xs)
{
    sort(xs.begin(), xs.end());
    xs.back() *= (1 << K);
    return accumulate(xs.begin(), xs.end(), 0);
}

int main()
{
    ios::sync_with_stdio(false);
    vector<int> xs(3);
    for (int i = 0; i < 3; i++)
        cin >> xs[i];

    int K;
    cin >> K;

    auto ans = solve(K, xs);

    cout << ans;

    return 0;
}