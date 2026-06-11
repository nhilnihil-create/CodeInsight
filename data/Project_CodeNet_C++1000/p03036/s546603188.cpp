#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll r,d;
    vector<ll> x(11);
    cin >> r >> d >> x[0];
    for (int i = 0; i <= 10; i++)
    {
        x[i+1] = r*x[i] - d;
    }
    for (int i = 1; i <= 10; i++)
    {
        cout << x[i] << endl;
    }
    return 0;
}