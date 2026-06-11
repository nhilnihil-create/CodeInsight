#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V.at(i);
    }

    int res = 0;
    for (int p = 1; p <= K && p <= N; p++)
    {
        for (int pl = 0; pl <= p; pl++)
        {
            int pr = p - pl;
            int s = 0;
            priority_queue<int> q;
            for (int i = 0; i < pl; i++)
            {
                s += V.at(i);
                q.push(-V.at(i));
            }
            for (int i = 0; i < pr; i++)
            {
                s += V.at(N - 1 - i);
                q.push(-V.at(N - 1 - i));
            }

            int mx = s;
            for (int i = 0; i < K - p; i++)
            {
                if (q.empty())
                    break;
                int b = q.top();
                q.pop();
                s += b;
                mx = max(mx, s);
            }
            res = max(res, mx);
        }
    }
    cout << res << endl;
    return 0;
}
