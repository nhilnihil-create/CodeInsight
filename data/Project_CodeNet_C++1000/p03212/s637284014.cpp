#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int n;
int ans = 0;

void func(ll x, bool three, bool five, bool seven)
{
    if (x > n)
        return;
    if (three && five && seven)
        ans++;

    func(x * 10 + 7, three, five, true);
    func(x * 10 + 5, three, true, seven);
    func(x * 10 + 3, true, five, seven);

    return;
}

int main()
{
    cin >> n;

    func(0, false, false, false);

    cout << ans << endl;
    return 0;
}