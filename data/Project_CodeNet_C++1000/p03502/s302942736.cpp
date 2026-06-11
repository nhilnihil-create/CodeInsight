#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

bool is_hershad(int x)
{
    int tmp = x;
    int res = 0;
    while (tmp)
    {
        res += tmp % 10;
        tmp /= 10;
    }
    return (x % res == 0);
}

int main()
{
    int n;
    cin >> n;

    cout << (is_hershad(n) ? "Yes" : "No") << endl;

    return 0;
}
