#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool Match(char c1, char c2)
{
    if (c1 == c2 || c1 == '?' || c2 == '?')
    {
        return true;
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size() - t.size();
    vector<int> id;
    bool gok = false;
    for (int i = 0; i <= n; ++i)
    {
        string ssub = s.substr(i, t.size());
        bool ok = true;
        for (int j = 0; j < ssub.size(); ++j)
        {
            if (!Match(ssub[j], t[j]))
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            gok = true;
            id.push_back(i);
        }
    }
    if (!gok)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    int start = *(id.end() - 1);
    for (int i = start; i < start + t.size(); ++i)
    {
        if (s[i] == '?')
        {
            s[i] = t[i - start];
        }
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '?')
        {
            s[i] = 'a';
        }
    }
    cout << s << endl;
    return 0;
}
