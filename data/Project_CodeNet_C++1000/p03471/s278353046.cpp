#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i <= n; i++)

int main()
{
    ll n, m, k;
    cin >> n >> m;
    rep(i, n)
    {
        rep(j, n - i)
        {
            k = n - i - j;
            if (m == i * 10000 + j * 5000 + k * 1000)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
