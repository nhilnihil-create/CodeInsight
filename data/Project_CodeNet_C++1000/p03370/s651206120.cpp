#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, x;
    cin >> n >> x;
    int ming = 1e9;
    rep(i, n)
    {
        int m;
        cin >> m;
        x -= m;
        if (ming > m)
            ming = m;
    }
    int cnt = n;
    while (x >= ming)
    {
        x -= ming;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}