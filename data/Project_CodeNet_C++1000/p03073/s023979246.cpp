#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    int nextColor = abs((s[0] - '0') - 1);
    for (int i = 1; i < n; i++)
    {
        if (nextColor != (s[i] - '0'))
            ans++;
        nextColor = abs(nextColor - 1);
    }

    cout << ans << endl;
    return 0;
}
