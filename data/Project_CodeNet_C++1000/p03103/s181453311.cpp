#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> s(n);
    rep (i, n)
        cin >> s[i].first >> s[i].second;

    ll ans = 0;
    int index = 0, cnt = 0;
    sort(s.begin(), s.end());
    rep (i, m)
    {
        ++cnt;
        if (cnt > s[index].second)
        {
            index++;
            cnt = 1;
        }
        ans += s[index].first;
    }

    cout << ans << endl;
    return 0;
}