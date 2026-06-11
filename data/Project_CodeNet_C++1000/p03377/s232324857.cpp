#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,x;
    cin >> a >> b >> x;
    if(a + b < x || a > x ) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}