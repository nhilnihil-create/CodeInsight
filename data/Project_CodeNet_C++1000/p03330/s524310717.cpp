#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int d[30][30];
int a[500][500];

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < c; ++j)
            cin >> d[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<int> v[3];
    for (int i = 0; i < 3; ++i)
        v[i].resize(c);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            v[(i + j) % 3][a[i][j] - 1]++;

    auto f = [&] (int i, int j, int k)
    {
        ll sum = 0;
        int ind[3] = {i, j, k};
        for (int l = 0; l < 3; ++l)
            for (int m = 0; m < c; ++m)
                sum += v[l][m] * d[m][ind[l]];
        return sum;
    };
    ll sol = 1e9;
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < c; ++j)
            for (int k = 0; k < c; ++k)
                if (i != j && j != k && i != k)
                    sol = min(sol, f(i, j, k));
    cout << sol;
}
