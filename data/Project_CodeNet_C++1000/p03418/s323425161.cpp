#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

// N以下で、bで割った余りがK以上のものの個数
ll f(ll b, ll N, ll K){
    if(b<=K) return 0;

    ll res = 0;

    // 周期的な部分の個数
    res += (N / b) * (b - K);

    // 半端な部分
    res += max((N % b) - max((K-1),(ll)0), (ll)0);

//    cerr << b << "," << res << endl;

    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (int b = 1; b <= N; b++) {
        ans += f(b, N, K);
    }

    cout << ans << endl;
}
