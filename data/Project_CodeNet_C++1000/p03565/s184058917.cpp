#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    bool restore = false;
    for (int i = s.size() - t.size(); i >= 0; i--)
    {
        bool replace = true;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != '?' && s[i + j] != t[j])
            {
                replace = false;
                break;
            }
        }
        if (replace == true)
        {
            restore = true;
            for (int j = 0; j < t.size(); j++)
                s[i + j] = t[j];
            break;
        }
    }
    if (restore == true)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?') cout << 'a';
            else cout << s[i];
        }
    }
    else cout << "UNRESTORABLE";
}
