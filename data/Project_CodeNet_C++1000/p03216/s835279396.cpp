#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<long> acc(n + 1);
    for (int i = 0; i < n; i++)
    {
        acc[i + 1] = acc[i] + (s[i] == 'D');
    }
    while (q--)
    {
        int k;
        cin >> k;
        long ans = 0, sum = 0;
        queue<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() + k == i)
            {
                sum -= acc[dq.front()];
                dq.pop();
            }
            if (s[i] == 'M')
            {
                dq.push(i);
                sum += acc[i];
            }
            if (s[i] == 'C')
            {
                ans += sum - acc[max(0, i - k + 1)] * dq.size();
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    solve();
    return 0;
}
