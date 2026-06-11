#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000010;

int solve(const vector<int> xs)
{
    vector<int> order(5);
    iota(order.begin(), order.end(), 0);

    int ans = oo;

    do
    {
        int t = 0;

        // Avalia cada uma das permutações possíveis
        for (int i  = 0; i < 4; ++i)
        {
            t += 10 * ((xs[order[i]] + 9)/ 10);
        }

        t += xs[order.back()];

        ans = min(ans, t);

    } while (next_permutation(order.begin(), order.end()));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    vector<int> xs(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> xs[i];
    }

    auto ans = solve(xs);

    cout << ans << endl;

    return 0;
}