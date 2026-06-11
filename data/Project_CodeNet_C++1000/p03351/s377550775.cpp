#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans = "No";
    if ((abs(a - b) <= d && abs(c - b) <= d) || abs(a - c) <= d)
    {
        ans = "Yes";
    }
    cout << ans << "\n";
    return 0;
}
