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
    ll A, B;
    cin >> A >> B;
    if (A == B)
    {
        cout << A << endl;
        return 0;
    }
    ll a_after = ((A + 3) / 4) * 4;
    ll b_before = (B / 4) * 4;
    ll ans = 0;
    for (ll i = A; i < a_after; i++)
    {
        ans ^= i;
    }
    for (ll i = b_before; i <= B; i++)
    {
        ans ^= i;
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
