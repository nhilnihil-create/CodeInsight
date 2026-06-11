#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    cin >> n >> a >> b;
    ll posl, pre;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(i == n - 2) pre = x;
        if(i == n - 1) posl = x;
    }
    ll res = abs(b - posl);
    if(n == 1) cout << res;
    else
    {
        if(abs(posl - pre) > res) res = abs(posl - pre);
        cout << res;
    }

    return 0;
}
