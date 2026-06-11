#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int D, G, p[11], c[11];
    cin >> D >> G;
    for (int i = 0; i < D; i++)
    {
        cin >> p[i] >> c[i];
    }

    int ans = 1e9;
    for (int mask = 0; mask < (1 << D); ++mask)
    {
        int s = 0, num = 0, rest_max = -1;
        for (int i = 0; i < D; i++)
        {
            if (mask >> i & 1)
            {
                s += 100 * (i + 1) * p[i] + c[i];
                num += p[i];
            }
            else
            {
                rest_max = i;
            }
        }
        if (s < G)
        {
            int s1 = 100 * (rest_max + 1);
            int need = (G - s + s1 - 1) / s1;
            if (need >= p[rest_max])
            {
                continue;
            }
            num += need;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
