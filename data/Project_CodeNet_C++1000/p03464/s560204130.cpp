/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int K_MAX = 100002;

int k;

ll a[K_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> a[i];
    a[0] = 1;
    ll mi = 2;
    for(int i = k; i >= 1; i--)
    {
        mi = (mi + a[i] - 1) / a[i];
        mi *= a[i];
        mi = (mi + a[i - 1] - 1) / a[i - 1] * a[i - 1];
    }
    ll mx = 2;
    for(int i = k; i >= 1; i--)
    {
        mx = (mx + a[i] - 1) / a[i];
        mx = mx * a[i] + a[i] - 1;
        mx = mx / a[i - 1] * a[i - 1];
    }
    ll val = mi;
    for(int i = 1; i <= k; i++)
        val = val / a[i] * a[i];
    if(val != 2)
        cout << "-1\n";
    else
        cout << mi << " " << mx << "\n";
    return 0;
}
