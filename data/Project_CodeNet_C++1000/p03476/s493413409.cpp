#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int q;
    cin >> q;
    int N = 100100;
    vector<int> is_prime(N, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    rep(i, N)
    {
        if (!is_prime[i])
        {
            continue;
        }
        for (int j = i * 2; j < N; j += i)
        {
            is_prime[j] = 0;
        }
    }

    vector<int> is_2017(N, 0), cum(N + 1, 0);
    for (int i = 1; i < N; i += 2)
    {
        if (is_prime[i] && is_prime[(i + 1) / 2])
        {
            is_2017[i] = 1;
        }
    }
    rep(i, N)
    {
        cum[i + 1] += cum[i] + is_2017[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << cum[r + 1] - cum[l] << endl;
    }

    return 0;
}