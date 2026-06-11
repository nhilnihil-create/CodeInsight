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
    int s;
    cin >> s;

    set<int> se;
    se.insert(s);

    int cnt = 1;
    int res = 1;

    while (1)
    {
        res++;
        se.insert(f(s));
        if (cnt == se.size())
        {
            cout << res << '\n';
            break;
        }
        cnt = se.size();
        s = f(s);
    }

    return 0;
}
