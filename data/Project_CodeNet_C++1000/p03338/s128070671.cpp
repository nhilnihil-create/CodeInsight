#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    int ans = 0;
    while (cur < n)
    {
        cur++;
        set<char> st;
        rep(i, cur) st.insert(s[i]);
        int cnt = 0;
        map<char, int> mp;
        for (int i = cur; i < n; i++)
        {
            if (st.count(s[i]) && !mp.count(s[i]))
            {
                cnt++;
                mp[s[i]]++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}