#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d)
    {
        cin >> p[i] >> c[i];
    }
    reverse(p.begin(), p.end());
    reverse(c.begin(), c.end());
    int sft = (int)pow(2, d - 1);
    int ans = 1000;
    rep(bit, 1 << d)
    {
        int score = 0, cnt = 0;
        rep(i, d)
        {
            if (bit & (sft >> i))
            {
                rep(j, p[i])
                {
                    score += (d - i) * 100;
                    cnt++;
                    if (score >= g)
                    {
                        ans = min(ans, cnt);
                        break;
                    }
                    if (j == p[i] - 1)
                    {
                        score += c[i];
                        if (score >= g)
                        {
                            ans = min(ans, cnt);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
