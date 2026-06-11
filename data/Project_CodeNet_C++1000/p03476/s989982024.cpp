#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_prime(long long n)
{
    if (n == 1)
        return false;
    for (long long i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    vector<int> sum(100000, 0);
    for (int i = 1; i < 100000; i++)
    {
        sum[i] = sum[i - 1];
        if ((i + 1) / 2 > 1 && is_prime(i) && is_prime((i + 1) / 2))
            sum[i]++;
    }
    int q;
    cin >> q;
    rep (i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}