#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1LL << 40;

// -------------------------------------------------------

ll N, K;

int main()
{
    cin >> N >> K;
    vector<vector<ll>> S(N);
    rep(i, 0, N)
    {
        ll t, d;
        cin >> t >> d;
        t--;
        S[t].push_back(d);
    }
    for (auto &v : S)
    {
        sort(v.begin(), v.end(), greater<ll>());
        if (v.empty())
            v.push_back(-INF);
    }

    sort(S.begin(), S.end(), [&](vector<ll> a, vector<ll> b) {
        return a[0] > b[0];
    });

    ll cur = 0;
    priority_queue<ll> que;
    for (int i = 0; i < K; i++)
    {
        cur += S[i][0];
        for (int j = 1; j < S[i].size(); j++)
        {
            que.push(S[i][j]);
        }
    }
    for (int i = K; i < N; i++)
    {
        for (int j = 0; j < S[i].size(); j++)
        {
            que.push(S[i][j]);
        }
    }
    ll res = cur + K * K;
    for (ll i = K - 1; i >= 1; i--)
    {
        ll v = S[i][0];
        ll w = que.top();
        if (w > v)
        {
            cur += w;
            cur -= v;
            que.pop();
            que.push(v);
        }
        chmax(res, cur + i * i);
    }
    cout << res << endl;
}
