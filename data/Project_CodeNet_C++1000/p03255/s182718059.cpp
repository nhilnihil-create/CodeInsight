#include<bits/stdc++.h>

using namespace std;

const long long MaxN = 2e5 + 17;
long long n, x;
long long v[MaxN];

long long f(long long k)
{
    long long ans = n * x;

    for(int i = 0; i < k; ++i)
    {
        vector<int> visit;
        visit.push_back(0);

        for(int j = i; j < n; j += k)
            visit.push_back(v[j]);

        long long m = visit.size();
        ans += visit[m - 1];

        for(int j = m - 1; j > 0; --j)
            ans += (visit[j] - visit[j - 1]) * (m - j + 1) * (m - j + 1);
    }

    return ans + k * x;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    for(long long i = 0; i < n; ++i)
        cin >> v[i];

    long long l = 1, r = n;

    while(r - l > 2)
    {
        long long t = (r - l) / 3;

        long long p1 = l + t;
        long long p2 = r - t;

        long long f1 = f(p1);
        long long f2 = f(p2);

        if(f2 > f1)
            r -= t;
        else
            l += t;
    }

    long long answer = 1e18;

    for(int i = l; i <= r; ++i)
        answer = min(answer, f(i));

    cout << answer << '\n';





}

