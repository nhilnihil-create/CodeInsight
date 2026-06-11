#include <bits/stdc++.h>
using namespace std;

void err()
{
    cout << -1 << '\n';
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    if (s[n - 1] != '0')
    {
        err();
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[n - 2 - i])
        {
            err();
        }
    }
    if (s[0] != '1')
    {
        err();
    }
    int last = 0;
    for (int i = 0; i < n-1; i++)
    {
        cout << last+1 << ' ' << i+2 << endl;
        if(s[i] == '1') last = i+1;
    }
    return 0;
}