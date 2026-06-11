#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N;
    cin >> N;
    vv<int> F(N, v<int>(10, 0));
    vv<ll> P(N, v<ll>(11, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> F[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> P[i][j];
        }
    }
    ll ans = INT32_MIN;
    for (int bit = 1; bit < (1 << 10); bit++)
    {
        ll ans_i = 0;
        for (int i = 0; i < N; i++)
        {
            int ci = 0;
            for (int j = 0; j < 10; j++)
            {
                if (bit & (1 << j))
                {
                    if (F[i][j] == 1)
                    {
                        ci++;
                    }
                }
            }
            ans_i += P[i][ci];
        }
        ans = max(ans, ans_i);
    }

    cout << ans << endl;

    return 0;
}