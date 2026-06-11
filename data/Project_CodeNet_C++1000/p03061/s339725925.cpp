#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int64_t gcd(int64_t p, int64_t q)
{
    if (p < q)
        swap(p, q);

    if (p % q == 0)
        return q;
    else
        return gcd(q, p % q);
}

int main()
{
    int N, ans = 0;
    cin >> N;
    vector<int> list(N), L(N), R(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    L[0] = list[0], R[N - 1] = list[N - 1];
    for (int i = 1; i < N; i++)
        L[i] = gcd(L[i - 1], list[i]);
    for (int i = N - 2; i >= 0; i--)
        R[i] = gcd(R[i + 1], list[i]);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        if (i == 0)
            tmp = R[1];
        else if (i == N - 1)
            tmp = L[N - 2];
        else
            tmp = gcd(L[i - 1], R[i + 1]);

        ans = max(ans, tmp);
    }
    cout << ans;
}