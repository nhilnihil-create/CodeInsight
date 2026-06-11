#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int a[31][100005];
int b[100005];

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        int s, t, x;
        cin >> s >> t >> x;
        a[x][s]++;
        a[x][t + 1]--;
    }
    for (int j = 1; j <= c; ++j)
        for (int i = 1; i <= 100000; ++i)
            a[j][i] += a[j][i - 1];

    int sol = 0;
    for (int i = 1; i <= 100000; ++i)
    {
        for (int j = 1; j <= c; ++j)
            a[j][i] = min(1, a[j][i]),
                b[i] += a[j][i];
        sol = max(sol, b[i]);
    }
    cout << sol;
}
