#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, T, A;
    cin >> N >> T >> A;
    A *= 1000, T *= 1000;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    int zure = mod, ans;
    for (int i = 0; i < N; i++)
    {
        double tmp = T - list[i] * 6;
        if (abs(A - tmp) < zure)
            ans = i, zure = abs(A - tmp);
    }
    cout << ans + 1;
}