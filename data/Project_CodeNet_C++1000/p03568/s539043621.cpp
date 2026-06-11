#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans, even = 0;
    bool flge = true;
    bool flgo = true;

    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            flge = false;
        }
        if (a[i] % 2 == 0)
        {
            flgo = false;
            even++;
        }
    }
    ans = pow(3, n);
    // cout << ans << endl;

    if (flgo)
    {
        ans -= 1;
    }
    else
    {
        ans -= pow(2, even);
    }

    cout << ans << endl;
    return 0;
}
