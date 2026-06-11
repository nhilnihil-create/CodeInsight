#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    int n; cin >> n;
    vector<string> s(n); for (i=0; i<n; i++) cin >> s[i];
    int m; cin >> m;
    vector<string> t(m); for (i=0; i<m; i++) cin >> t[i];
    int max_point = 0, point = 0;
    bool different = true;
    vector<string> str(1, s.at(0));
    int str_len = str.size();

    for (i=1; i<n; i++)
    {
        different = true;
        str_len = str.size();
        for (j=0; j<str_len; j++)
        {
            if (str.at(j) == s.at(i)) {different = false; break;}
        }
        if (different) str.push_back(s.at(i));
    }
    for (i=0; i<m; i++)
    {
        different = true;
        str_len = str.size();
        for (j=0; j<str_len; j++)
        {
            if (str.at(j) == t.at(i)) {different = false; break;}
        }
        if (different) str.push_back(t.at(i));
    }

    str_len = str.size();
    for (i=0; i<str_len; i++)
    {
        point = 0;
        for (j=0; j<n; j++)
        {
            if (s.at(j) == str.at(i)) point++;
        }
        for (j=0; j<m; j++)
        {
            if (t.at(j) == str.at(i)) point--;
        }
        if (max_point < point) max_point = point;
    }
    cout << max_point << endl;
}