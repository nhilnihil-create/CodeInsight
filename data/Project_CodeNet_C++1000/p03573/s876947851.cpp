#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int a, b, c, ans;
    cin >> a >> b >> c;
    if (a == b)
    {
        ans = c;
    }
    else if (b == c)
    {
        ans = a;
    }
    else if (c == a)
    {
        ans = b;
    }
    cout << ans << "\n";
    return 0;
}
