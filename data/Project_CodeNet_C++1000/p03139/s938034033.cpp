#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    int ans = x + y - n;
    if(ans <= 0) ans = 0;
    cout << min(x,y) << " " << ans << endl;
    return 0;
}