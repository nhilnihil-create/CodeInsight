#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a+b > c+d) cout << "Left" << endl;
    else if(a+b == c+d) cout << "Balanced" << endl;
    else cout << "Right" << endl;
    return 0;
}