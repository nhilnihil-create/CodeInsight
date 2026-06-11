#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll k, a, b; cin >> k >> a >> b;
    ll cur = 0;
    if(a < b) {
        ll tim = k - (a - 1);
        if(tim >= 2) {
            cur += b;
        }
        cur += ((tim - 2) / 2) * (b - a);
        cur += (tim % 2);
    }
    //cout << cur << endl;
    cout << max(cur, k + 1) << endl;
}