#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n;
    cin >> n;

    string ans = "No";
    rep(i, n / 4 + 1)
    {
        rep(j, n / 7 + 1)
        {
            if (4 * i + 7 * j == n)
            {
                ans = "Yes";
            }
        }
    }

    cout << ans << endl;

    return 0;
}
