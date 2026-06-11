#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep2(i, 1, n - 1)
    {
        string x, y;
        x = s.substr(0, i);
        y = s.substr(i);
        int cnt = 0;
        rep(j, x.size())
        {
            bool flag = true;
            rep(k, j)
            {
                if (x[j] == x[k])
                {
                    flag = false;
                }
            }
            if (y.find(x[j]) != -1 && flag)
            {
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }

    cout << ans << '\n';
    return (0);
}
