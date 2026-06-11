// https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    int cont = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' | s[i] == 'C' | s[i] == 'G' | s[i] == 'T')
        {
            cont++;
        }
        else
        {
            ans = max(ans, cont);
            cont = 0;
        }
    }
    ans = max(ans, cont);
    cout << ans << endl;
}
