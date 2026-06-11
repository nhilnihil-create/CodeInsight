#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        string t = s.substr(0, i);
        string u = s.substr(i);
        int cnt = 0;
        // cout << t << " " << u << endl;
        vector<int> num1(30), num2(30);
        for (int j = 0; j < (int)t.size(); j++)
        {
            num1[t[j] - 'a']++;
        }
        for (int j = 0; j < (int)u.size(); j++)
        {
            num2[u[j] - 'a']++;
        }
        for (int j = 0; j < 30; j++)
        {
            // cout << num1[j] << " " << num2[j] << endl;
            if (num1[j] > 0 && num2[j] > 0)
                cnt++;
        }
        // cout << endl;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}