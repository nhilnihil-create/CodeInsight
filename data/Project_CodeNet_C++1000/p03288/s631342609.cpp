#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int r;
    cin >> r;
    if(r < 1200) cout << "ABC" << endl;
    else if(r < 2800 && 1200 <= r) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    return 0;
}