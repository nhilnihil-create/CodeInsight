#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> value(n), cost(n);

    for (auto &x : value)
        cin >> x;

    for (int &x : cost)
        cin >> x;

    int answer = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (cost[i] < value[i])
            sum += value[i] - cost[i];

        answer = max(answer, sum);
    }

    cout << answer << endl;

    return 0;
}