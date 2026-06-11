#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;

int main()
{
    int A, B;
    cin >> A >> B;

    if (A >= 13)
    {
        cout << B;
    }
    else if (A >= 6)
    {
        cout << B / 2;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
