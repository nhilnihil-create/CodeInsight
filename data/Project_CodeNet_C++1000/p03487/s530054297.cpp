#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
const long long INF = 1LL << 60;
ll mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a] += 1;
    }
    int ans = 0;
    for (auto i : mp)
    {
        if (i.first > i.second)
        {
            ans += i.second;
        }
        else
        {
            ans += abs(i.second - i.first);
        }
    }
    cout << ans << endl;
    return 0;
}
