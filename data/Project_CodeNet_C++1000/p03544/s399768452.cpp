#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

ll num[100];

ll luca_number(int n)
{
    if (num[n] != 0)
    {
        return num[n];
    }

    if (n == 0)
    {
        return num[n] = 2LL;
    }
    else if (n == 1)
    {
        return num[n] = 1LL;
    }
    return num[n] = luca_number(n - 1) + luca_number(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << luca_number(n) << endl;
    return 0;
}
