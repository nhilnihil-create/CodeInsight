#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll p = a[0];
    ll q = 0;
    ll r = a[1] + a[2];
    ll s = 0;
    for(int i = 3; i < n; i++)
    {
        s += a[i];
    }

    ll ans = 1e10;
    ll left = 0;
    ll right = 2;
    ll ma = 0, mi = 0;
    for(int pos = 1; pos < n-2; pos++)
    {
        q += a[pos];
        r -= a[pos];
        while(left < pos-1)
        {
            if(abs(p-q) > abs(p+a[left+1] - (q-a[left+1])))
            {
                p += a[left+1];
                q -= a[left+1];
                left++;
            }
            else
            {
                break;
            }
        }

        if(right == pos)
        {
            right++;
            r = a[right];
            s -= r;
        }
        while(right < n-2)
        {
            if(abs(r-s) > abs(r+a[right+1] - (s-a[right+1])))
            {
                r += a[right+1];
                s -= a[right+1];
                right++;
            }
            else
            {
                break;
            }
        }
        ma = max(max(p, q), max(r, s));
        mi = min(min(p, q), min(r, s));
        ans = min(ans, ma-mi);
    }
    cout << ans << endl;
}
