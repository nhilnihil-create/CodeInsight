#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = a;
    if (b < a)
    {
        ans = a - 1;
    }
    cout << ans << "\n";
    return 0;
}
