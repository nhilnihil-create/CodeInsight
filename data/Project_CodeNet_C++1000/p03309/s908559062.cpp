#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        ll k;
        cin >> k;
        a[i] = k - 1 - i;
    }
    sort(a.begin(), a.end());
    int b = 0;
    b = a[n / 2];
    ll count = 0;
    rep(i, n)
    {
        count += labs(b - a[i]);
    }
    cout << count << endl;
}