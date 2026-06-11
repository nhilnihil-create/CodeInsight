#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

bool prime_factrization(const int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int Q;
    cin >> Q;

    const int MAX = 100001;

    vector<int> sum(MAX);
    sum[0] = sum[1] = sum[2] = 0;

    for (int i = 3; i < MAX; ++i)
        sum[i] = sum[i - 1] + (prime_factrization(i) && prime_factrization((i + 1) / 2));

    rep(q, Q)
    {
        int l, r;
        cin >> l >> r;

        cout << sum[r] - sum[l - 1] << endl;
    }
}