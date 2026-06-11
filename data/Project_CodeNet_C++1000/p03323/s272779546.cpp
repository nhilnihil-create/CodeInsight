#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a, b;
    cin >> a >> b;
    if(a < 9 && b < 9) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}