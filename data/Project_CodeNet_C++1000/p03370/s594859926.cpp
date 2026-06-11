#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N, X, m, sum = 0, imin = 1100;

    cin >> N >> X;

    rep(i, N)
    {
        cin >> m;
        sum += m;

        if (m < imin)
            imin = m;
    }

    cout << N + (X - sum) / imin << endl;

    return 0;
}