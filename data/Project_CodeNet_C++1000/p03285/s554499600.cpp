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

    int n4 = n / 4 + 1;
    int n7 = n / 7 + 1;

    bool flag = false;
    rep(i, n4)
    {
        rep(j, n7)
        {
            if (4 * i + 7 * j == n)
            {
                flag = true;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
