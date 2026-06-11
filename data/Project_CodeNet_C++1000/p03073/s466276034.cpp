#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    ll ans[] = {0, 0};
    rep(c, 2)
    {
        int color = c;
        for (char s : S)
        {
            int s_i = s - '0';
            if (color != s_i)
                ans[c]++;
            color = 1 - color;
        }
    }
    cout << min(ans[0], ans[1]) << endl;

    return 0;
}
