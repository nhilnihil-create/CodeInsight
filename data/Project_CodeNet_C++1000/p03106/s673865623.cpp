#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    for (int i = min(a, b); i >= 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            k--;
        }
        if (!k)
        {
            cout << i << endl;
            break;
        }
    }
    return (0);
}
