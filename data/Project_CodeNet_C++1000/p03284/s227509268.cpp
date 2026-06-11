#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    if (n % k == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << 1 << "\n";
    }
    return 0;
}
