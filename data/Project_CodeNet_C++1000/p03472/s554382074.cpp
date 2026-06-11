#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5+5 , M = 998244353, OO = 0x3f3f3f3f;
typedef long long ll;
ll n, h;
ll a[N], b[N];
int main()
{
    cin >> n >> h;
    for(int i=0; i<n; ++i) cin >> a[i] >> b[i];
    ll mx = a[0];
    for(int i=1; i<n; ++i) mx=max(mx, a[i]);
    sort(b, b+n);
    ll u = 0;
    ll sum = 0;
    bool f = 1;
    for(int i=n-1; i>=0; --i)
    {
        if(b[i] > mx)
        {
            u++;
            sum+=b[i];
            if(sum >= h)
            {
                f=0;
                break;
            }
        }
        else break;
    }
    if(!f)
    {
        cout << u << endl;
        return 0;
    }
    ll rem = h - sum;
    ll d = (rem+mx-1)/mx;
    cout << (d+u) << endl;
    return 0;
}
