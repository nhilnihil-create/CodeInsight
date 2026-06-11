#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int n = s.size();
    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
            c0++;
        else
            c1++;
    }

    cout << 2 * min(c0, c1);

    return 0;
}
