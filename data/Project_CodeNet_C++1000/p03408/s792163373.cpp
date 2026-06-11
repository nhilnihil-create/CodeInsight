#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[n];
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        v.push_back(s[i]);
    }
    int m;
    cin >> m;
    string t[m];
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
        v.push_back(t[i]);
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i] == s[j])
                cnt++;
        }
        for (int j = 0; j < m; j++)
        {
            if (v[i] == t[j])
                cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
