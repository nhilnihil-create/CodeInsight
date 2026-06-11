#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5e3 + 5;

int n, A, B;
int pos[MaxN], a[MaxN];
long long f[MaxN][MaxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    memset(f, 100, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (pos[i] > pos[j])
            {
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + B);
                f[i + 1][i] = min(f[i][j], f[i + 1][i]);
            }
            else
            {
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + A);
            }
        }
    }
    long long res = *min_element(f[n + 1], f[n + 1] + n + 1);
    cout << res;
    return 0;
}
