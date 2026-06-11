#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

const int INF = 1001001001;

int ck(int a)
{
    if (a == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int q;
    cin >> q;

    int MAX = 100100;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (is_prime[i] == 0)
            continue;
        for (int j = i * 2; j < MAX; j += i)
        {
            is_prime[j] = 0;
        }
    }

    vector<int> a(MAX, 0);
    for (int i = 0; i < MAX; ++i)
    {
        if (i % 2 == 0)
            continue;
        if (is_prime[i] && is_prime[(i + 1) / 2])
            a[i] = 1;
    }

    vector<int> cum(MAX + 1, 0);
    rep(i, MAX)
    {
        cum[i + 1] = cum[i] + a[i];
    }

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        r++;
        cout << cum[r] - cum[l] << endl;
    }

    return 0;
}