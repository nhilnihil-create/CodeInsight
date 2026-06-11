#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, a[202020];

int main()
{
    cin >> n;
    rep(i, n) cin >> a[i];

    ll res = n;
    int x = a[0], right = 0;
    for(int i = 0; i < n; i++)
    {
        while(right + 1 < n && (x + a[right + 1]) == (x ^ a[right + 1]))
        {
            x += a[right + 1];
            right++;
        }
        res += right - i;
        x ^= a[i];
    }
    cout << res << endl;

    return 0;
}