#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    string ans = "NO";
    if (a + b >= x && a <= x)
        ans = "YES";
    cout << ans << "\n";
    return 0;
}
