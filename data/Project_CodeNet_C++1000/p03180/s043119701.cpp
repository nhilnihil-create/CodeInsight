#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 17;

int a[N][N];
ll val[1 << N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    fill(val, val + (1 << n), 0);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (int k = j + 1; k < n; k++)
                    if (i & (1 << k))
                        val[i] += a[j][k];
    for (int i = 0; i < (1 << n); i++)
        for (int j = i; j; j = (j - 1) & i)
            val[i] = max(val[i], val[j] + val[i ^ j]);
    cout << val[(1 << n) - 1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
