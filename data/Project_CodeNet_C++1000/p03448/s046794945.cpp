#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int A, B, C, X;

int main()
{
    cin >> A >> B >> C >> X;

    int res = 0;

    rep(i, A + 1)
        rep(j, B + 1)
            rep(k, C + 1)
    {
        if (500 * i + 100 * j + 50 * k == X)
            res++;
    }

    cout << res << endl;
    return 0;
}