#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int divide_2(int n)
{
    int res = 0;
    while (n % 2 == 0 && n)
    {
        res++;
        n /= 2;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    bool odd = true;
    rep(i, n) if (a[i] % 2 == 0) odd = false;

    rep(i, n)
    {
        if (a[i] % 2 == 0)
        {
            cnt += divide_2(a[i]);
        }
    }

    cout << ((odd) ? 0 : cnt) << '\n';
    return (0);
}
