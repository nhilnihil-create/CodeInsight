#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;

    //BCをDに変換したneを作成
    string ne = "";
    rep(i, s.length() - 1)
    {
        if (s[i] == 'B' && s[i + 1] == 'C')
        {
            ne += 'D';
            i++;
        }
        else
            ne += s[i];
    }
    if (ne[ne.length() - 1] != 'D')
        ne += s[s.length() - 1];

    ll ans = 0, cnt = 0;
    rep(i, ne.length())
    {
        if (ne[i] == 'A')
            cnt++;
        else if (ne[i] == 'D')
            ans += cnt;
        else
            cnt = 0;
    }

    cout << ans << endl;
}