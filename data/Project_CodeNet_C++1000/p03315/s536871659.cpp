#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans << endl;

    return 0;
}
