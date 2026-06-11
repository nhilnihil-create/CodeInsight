#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll sum = 0;
    ll m = 1e10;
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        sum += a;
        if(a > b)
        {
            flag = false;
            m = min(m, b);
        }
    }
    if(flag) cout << 0 << endl;
    else  cout << sum - m << endl;
}

