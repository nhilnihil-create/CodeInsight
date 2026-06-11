#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int res = 0;
    rep(i, 4)
    {
        char n;
        cin >> n;
        if (n == '2')
            res++;
    }
    cout << res << endl;
    // end

    return 0;
}
