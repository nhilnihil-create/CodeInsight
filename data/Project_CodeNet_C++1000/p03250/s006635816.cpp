#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int f(int n)
{
    return ((n & 1) ? 3 * n + 1 : n / 2);
}

int main()
{
    vector<int> v(3);
    rep(i, 3) cin >> v[i];

    sort(all(v));
    reverse(all(v));

    cout << v[0] * 10 + v[1] + v[2] << '\n';
    return 0;
}
