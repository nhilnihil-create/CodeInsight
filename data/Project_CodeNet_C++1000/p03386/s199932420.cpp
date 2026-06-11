#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;

    if (b - k + 1 <= a + k - 1)
    {
        rem(i, a, b + 1)
        {
            cout << i << "\n";
        }
    }
    else
    {
        rem(i, a, a + k)
        {
            cout << i << "\n";
        }
        rem(i, b - k + 1, b + 1)
        {
            cout << i << "\n";
        }
    }

    return 0;
}