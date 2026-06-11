#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    char ans = '1';
    long k;
    int i;
    cin >> s >> k;
    for (int i = 0; i < k; ++i)
    {
        if (s[i] != '1')
        {
            ans = s[i];
            break;
        }
    }
    cout << ans << endl;
}