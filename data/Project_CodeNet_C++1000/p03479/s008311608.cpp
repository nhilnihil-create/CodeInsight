#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
ll X, Y;
void func()
{
    cin >> X >> Y;
    ll ans = 0;
    while (X <= Y)
    {
        X *= 2;
        ++ans;
    }
    cout << ans << endl;
}
int main()
{
    func();
}