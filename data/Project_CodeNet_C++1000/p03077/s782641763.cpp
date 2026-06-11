#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
ll N, A, B, C, D, E;
ll func2(ll a, ll b)
{
    return (a % b == 0) ? a / b : a / b + 1;
}
void func()
{
    cin >> N >> A >> B >> C >> D >> E;
    ll ans = 0;
    ll min = A;
    ans = func2(N, A);
    if (B >= min)
        ans += 1;
    if (B < min)
        min = B, ans = func2(N, B) + 1;
    if (C >= min)
        ans += 1;
    if (C < min)
        min = C, ans = func2(N, C) + 2;
    if (D >= min)
        ans += 1;
    if (D < min)
        min = D, ans = func2(N, D) + 3;
    if (E >= min)
        ans += 1;
    if (E < min)
        ans = func2(N, E) + 4;
    cout << ans << endl;
}
int main()
{
    func();
}