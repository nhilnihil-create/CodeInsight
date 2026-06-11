#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int t;
    int start[N + 2] = {};
    int goal[N + 2] = {};
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        goal[i] = start[i] + 2 * t;
        start[i + 1] = goal[i];
    }
    goal[N + 1] = goal[N];

    int v[N + 2] = {};
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
        v[i] *= 2;
    }

    vector<int> x(goal[N] + 1, INT_MAX);
    x[0] = 0;
    int ans = 0;
    for (int i = 1; i < goal[N] + 1; i++)
    {
        for (int j = 0; j < N + 2; j++)
        {
            if (i < start[j])
            {
                x[i] = min(x[i], v[j] + start[j] - i);
            }
            else if (goal[j] < i)
            {
                x[i] = min(x[i], v[j] + i - goal[j]);
            }
            else
            {
                x[i] = min(x[i], v[j]);
            }
        }
        ans += x[i - 1] + x[i];
    }
    cout << setprecision(10) << (double)ans / 8 << endl;
}
