#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c, d;
    string s;

    cin >> n >> a >> b >> c >> d >> s;
    a--;b--;c--;d--;

    string ans = "Yes";
    if(c < d)
    {
        for (int i = b; i <= d - 1; i++)
        {
            if(s[i] == '#' && s[i + 1] == '#')ans = "No";
        }
        for (int i = a; i <= c - 1; i++)
        {
            if(s[i] == '#' && s[i + 1] == '#')ans = "No";
        }
    }
    else
    {
        ans = "No";
        for (int i = b - 1; i <= d - 1; i++)
        {
            if(s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')ans = "Yes";
        }
    }
    cout << ans << endl;
}