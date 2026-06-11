#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a;

    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    ll i = 0;
    ll ans = 0;

    for (int i = 0; i < a.size(); ++i)
    {

        if (x >= a[i])
        {
            x -= a[i];
            ++ans;
        }
        else
        {
            cout << ans << endl;
            return 0;
        }
    }
    if (x > 0)
    {
        cout << ans - 1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
