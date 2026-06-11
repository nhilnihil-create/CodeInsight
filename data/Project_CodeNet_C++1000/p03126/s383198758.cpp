#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> food(m);
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int x;
            cin >> x;
            x--;
            food[x]++;
        }
    }
    int ans = 0;
    rep(i, m) if (food[i] == n) ans++;
    cout << ans << endl;
    return 0;
}