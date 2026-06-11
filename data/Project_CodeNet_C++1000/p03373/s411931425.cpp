#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int cost = 1000000000;
    rep(i, 0, max(2 * x + 1, 2 * y + 1))
    {
        int now = 0;
        now += c * i;
        now += max(0, x - i / 2) * a;
        now += max(0, y - i / 2) * b;
        // cout <<  max(0, x - i / 2) << ' ' <<  max(0, y - i / 2) << ' ' << i << endl;
        cost = min(cost , now);
    }
    cout << cost << endl;
    return 0;
}