#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= c && c <= b || b <= c && c <= a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}