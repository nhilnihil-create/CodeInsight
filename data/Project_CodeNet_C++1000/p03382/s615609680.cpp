#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    set<ll> a;
    for(int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    set<ll>::iterator itr = a.end();
    ll x = *--itr;
    ll y = 0;
    ll border = x/2;
    if(x % 2 == 1) border++;
    ll cand1 = *lower_bound(a.begin(), a.end(), border);
    ll cand2 = *--lower_bound(a.begin(), a.end(), border);
    ll c1 = abs(cand1 - border);
    ll c2 = abs(cand2 - border);
    if(c1 < c2)
    {
        y = cand1;
    }
    else
    {
        y = cand2;
    }
    cout << x << " " << y << endl;
}

