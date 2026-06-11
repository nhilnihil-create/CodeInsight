#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < 3; i++)
    {
        if(s[i] != 'x')
            cnt++;
    }

    cout << 700 + cnt * 100;

    return 0;
}
