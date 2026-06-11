#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max(a, max(b, c));
    mx *= 3;
    int sum = a + b + c;
    if ((mx - sum) % 2 == 0)
    {
        cout << (mx - sum) / 2 << endl;
    }
    else
    {
        mx += 3;
        cout << (mx - sum) / 2 << endl;
    }
    return 0;
}