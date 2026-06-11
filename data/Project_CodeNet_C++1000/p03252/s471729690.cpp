#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    bool ans = true;
    cin >> s >> t;
    vector<int> table_s(26, 0), table_t(26, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        table_s[s[i] - 'a']++;
        table_t[t[i] - 'a']++;
    }
    sort(table_s.begin(), table_s.end());
    sort(table_t.begin(), table_t.end());
    for (int i = 0; i < table_s.size(); ++i)
    {
        if (table_s[i] != table_t[i])
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}