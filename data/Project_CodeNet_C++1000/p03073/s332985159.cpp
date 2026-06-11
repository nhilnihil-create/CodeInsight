#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    char c = s[0];
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            if (c != s[i])
                cnt1++;
        }
        else
        {
            if (c == s[i])
                cnt1++;
        }
    }
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            if (c == s[i])
                cnt2++;
        }
        else
        {
            if (c != s[i])
                cnt2++;
        }
    }
    int ans = min(cnt1, cnt2);
    cout << ans << endl;
    return 0;
}