#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

bool stg(long long x, long long a, long long b)
{
    if (x == 4)
        cout << "";
    vector<long long> v;
    if (b <= x)
    {
        if (a - 1 > x - (b - 1))
        {
            v.push_back(x - (b - 1));
            v.push_back(a - 1 - (x - (b - 1)));
            v.push_back(x - (a - 1));
        }
        else
        {
            v.push_back(a - 1);
            v.push_back(x - (b - 1) - (a - 1));
            v.push_back(b - 1);
        }
    }
    else if (a <= x)
    {
        v.push_back(a - 1);
        v.push_back(x - (a - 1));
    }
    else
    {
        v.push_back(x);
    }
    long long ua = 1;
    long long ub = x;
    if (b <= x)
        ++ub;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == 0)
            continue;
        if (ua == a)
            ++ua;
        if (ub == b)
            --ub;
        long long ra = ua + v[i] - 1;
        long long lb = ub - v[i] + 1;
        if (ua * ub >= a * b)
            return false;
        if (ra * lb >= a * b)
            return false;
        if (ra <= ub)
        {
            if (lb <= ra)
            {
                int d = (ra - lb + 1);
                if ((ra - (d / 2)) * (lb + (d / 2)) >= a * b)
                    return false;
            }
        }
        else
        {
            if (ua <= ub)
            {
                int d = (ub - ua + 1);
                if ((ua + (d / 2)) * (ub - (d / 2)) >= a * b)
                    return false;
            }
        }
        ua += v[i];
        ub -= v[i];
    }
    return true;
}

void solv()
{
    int aa, bb;
    scanf("%d%d", &aa, &bb);
    if (aa > bb)
        swap(aa, bb);
    long long l = 1, r = 2000000000;
    long long ans = 0;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (stg(m, aa, bb))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%lld\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
    for (int i = 1; i <= 300; ++i)
    {
        set<int> s;
        for (int j = 1; j <= i; ++j)
            s.insert(i / j);
        printf("%d %d\n", i, s.size());
    }
    return 0;
}
