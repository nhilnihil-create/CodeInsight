#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    ll K, A, B;
    cin >> K >> A >> B;
    ll ans = 1;
    if (K - A + 1 > 0)
    { // A枚になるまで叩く
        ans = A;
        K -= A - 1;
    }
    else
    {
        cout << 1 + K << endl;
        return 0;
    }
    if (B - A >= 3)
    {
        ll cnt = K / 2;
        ans += (cnt * (B - A));
        ans += K % 2;
        cout << ans << endl;
        return 0;
    }
    else
    {
        cout << ans + K << endl;
        return 0;
    }
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
