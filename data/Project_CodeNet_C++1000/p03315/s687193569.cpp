#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    rep(i, 4)
    {
        if (s[i] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans << '\n';
    return (0);
}
