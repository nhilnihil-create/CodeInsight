#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        if (temp <= A)
        {
            ++a;
        }
        else if (temp >= B + 1)
        {
            ++b;
        }
        else
        {
            ++c;
        }
    }
    ll ans = min(min(a, b), c);
    cout << ans << endl;
}
