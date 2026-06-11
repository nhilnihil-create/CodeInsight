#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
const long long MOD = 1e9 + 7, INF = 1e18;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> a(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    a[N] = 0;
    int ans = INF;
    for (int i = 0; i < N + 1; i++)
    {
        int ng = a[i];
        vector<int> v;
        vector<int> tmp;
        for (int j = 0; j < N; j++)
        {
            if (a[j] <= ng)
            {
                if (tmp.size() >= K)
                {
                    sort(tmp.begin(), tmp.end());
                    for (int k = 0; k < min(Q, (int)tmp.size() - K + 1); k++)
                    {
                        v.push_back(tmp[k]);
                    }
                }
                tmp.clear();
            }
            else
            {
                tmp.push_back(a[j]);
            }
            if (j == N - 1)
            {
                if (tmp.size() < K)
                    continue;
                sort(tmp.begin(), tmp.end());
                for (int k = 0; k < min(Q, (int)tmp.size() - K + 1); k++)
                {
                    v.push_back(tmp[k]);
                }
                tmp.clear();
            }
        }
        sort(v.begin(), v.end());
        if ((int)v.size() >= Q)
        {
            chmin(ans, v[Q - 1] - v[0]);
        }
    }
    cout << ans << endl;
}