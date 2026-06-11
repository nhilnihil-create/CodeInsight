#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    char x, y, ans = '=';
    cin >> x >> y;
    if (x < y)
        ans = '<';
    if (x > y)
        ans = '>';
    cout << ans << "\n";
    return 0;
}
