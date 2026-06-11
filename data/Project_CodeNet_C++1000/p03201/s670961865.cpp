#include <bits/stdc++.h>
using namespace std;

long long calc_target(long long x)
{
    long long target = 1;
    long long exp = 0;
    while (x > 0)
    {
        if (~x & 1)
        {
            target += (1 << exp);
        }
        exp++;
        x >>= 1;
    }
    return target;
}

int main()
{
    int N;
    cin >> N;

    long long A;
    map<long long, int> m;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        m[A]++;
    }

    long long ans = 0;
    for (auto itr = m.rbegin(); itr != m.rend(); itr++)
    {
        long long target = calc_target(itr->first);
        while (itr->second > 0)
        {
            itr->second--;
            if (m[target] > 0)
            {
                m[target]--;
                ans++;
            }
            else
            {
                itr->second++;
                break;
            }
        }
    }
    cout << ans << endl;
}
