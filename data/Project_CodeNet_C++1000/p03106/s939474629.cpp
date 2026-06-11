#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = min(a, b); i >= 1; --i)
        if (a % i == 0 && b % i == 0)
            if (--k == 0)
            {
                cout << i << endl;
                return 0;
            }
}