#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    char x, y, ans = '=';
    cin >> x >> y;
    if ((int)x < (int)y)
        ans = '<';
    if ((int)x >(int) y)
        ans = '>';
    cout << ans << "\n";
    return 0;
}
