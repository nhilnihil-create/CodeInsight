#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pref(n), suff(n);
    pref[0] = (s[0] == 'W' ? 1 : 0);
    suff[n - 1] = (s[n - 1] == 'E' ? 1 : 0);
    for(int i = 1; i < n; i++)
    {
        if(s[i] == 'W')
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(s[i] == 'E')
            suff[i] = suff[i + 1] + 1;
        else
            suff[i] = suff[i + 1];
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++)
    {
        int cur = 0;
        if(i == 0)
            cur = suff[i + 1];
        else if(i == n - 1)
            cur = pref[i - 1];
        else
            cur = pref[i - 1] + suff[i + 1];
        ans = min(ans, cur);
    }

    cout << ans;

    return 0;
}
