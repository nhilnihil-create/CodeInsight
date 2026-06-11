#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    ll n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1 || m == 1)
    {
        cout << max(n - 2, m - 2) << endl;
        return 0;
    }
    cout << (n - 2) * (m - 2) << endl;
    return 0;
}