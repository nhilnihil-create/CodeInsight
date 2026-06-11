#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    rep(i, N) { cin >> V[i]; }

    ll res = 0;
    rep(a, min(N, K) + 1)
    {
        rep(b, min(N - a, K - a) + 1)
        {
            vector<ll> tmp;
            rep(i, a) { tmp.push_back(V[i]); }
            rep(i, b) { tmp.push_back(V[N - i - 1]); }

            sort(tmp.begin(), tmp.end());
            ll cur_sum = std::accumulate(tmp.begin(), tmp.end(), 0);

            int r = min(K - (a + b), int(tmp.size()));
            rep(i, r)
            {
                if (tmp[i] < 0)
                {
                    cur_sum -= tmp[i];
                }
            }

            res = max(res, cur_sum);
        }
    }

    cout << res << endl;
}
