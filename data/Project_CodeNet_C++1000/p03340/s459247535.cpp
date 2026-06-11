#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
using namespace std;

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll sum = 0, res = 0, right = 0;
    rep(left, 0, n)
    {
        while (right < n && ((sum ^ a[right]) == (sum + a[right])))
            sum += a[right], right++;
        res += right - left;
        if (left == right)
            ++right;
        else
            sum -= a[left];
    }
    cout << res << endl;
}
