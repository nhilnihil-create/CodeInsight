#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, K;
void func()
{
    cin >> N >> K;
    int ans(1);
    rep(i, 0, N)
    {
        if (ans < K)
            ans *= 2;
        else
            ans += K;
    }
    cout << ans << endl;
}
int main()
{
    func();
}