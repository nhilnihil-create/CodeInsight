// AtCoder Beginner Contest 092 - Problem D: Grid Components (https://atcoder.jp/contests/abc092/tasks/arc093_b)
#include <bits/stdc++.h>

using namespace std;

const int MAX { 100 };

vector<string> solve(int A, int B)
{
    vector<string> ans(MAX, string(MAX, '.'));

    int x = 0, y = 0;

    if (A > 1)
        B--;

    // A região conectada bracn é um ponto branco envolto por uma borda preta
    while (--A)
    {
        if (y + 1 >= MAX)
        {
            y = 0;
            x += 3;
        }

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ans[x + i][y + j] = '#';

        ans[x + 1][y + 1] = '.';
        y += 3;
    }


    // A região conectada preta é um ponto envolto por uma borda branca
    while (B--)
    {
        if (y + 1 >= MAX)
        {
            y = 0;
            x += 3;
        }

        ans[x + 1][y + 1] = '#';

        y += 3;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    cout << MAX << ' ' << MAX << '\n';

    auto ans = solve(A, B);

    for (const auto& x : ans)
        cout << x << '\n';

    return 0;
}
