#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    bool equal = true;
    for (int i = 0; i < s.size() && i < t.size(); i++)
    {
        if (s[i] < t[i])
        {
            equal = false;
            break;
        }
    }
    if (equal == false) cout << "Yes";
    else
    {
        for (int i = 0; i < s.size() && i < t.size(); i++)
        {
            if (s[i] != t[i])
            {
                equal = false;
                break;
            }
        }
        if (equal == true && s.size() < t.size()) cout << "Yes";
        else cout << "No";
    }
}