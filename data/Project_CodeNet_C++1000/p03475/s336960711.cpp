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
    v<int> C(N - 1), S(N - 1), F(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> C[i] >> S[i] >> F[i];
    }

    v<ll> ans(N, 0);

    for (int i = 0; i < N - 1; i++)
    {
        ll time = S[i] + C[i];
        for (int j = i + 1; j < N - 1; j++)
        {
            if (time < S[j])
            {
                time = S[j] + C[j];
            }
            else
            {
                time = S[j] + ceil(((double)time - S[j]) / F[j]) * F[j] + C[j];
            }
        }
        ans[i] = time;
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}