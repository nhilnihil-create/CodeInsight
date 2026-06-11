#include <bits/stdc++.h>

#define NM 1002
#define ll long long
#define MM 102

using namespace std;

ll n, X[NM], Y[NM];

int m = 39;

ll d[MM];

ll x[MM], y[MM];

int main()
{
    cin >> n;
    bool ok = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
        if(abs(X[i] + Y[i]) % 2 != abs(X[1] + Y[1]) % 2)
            ok = false;
    }
    if(!ok)
    {
        cout << "-1\n";
        return 0;
    }
    d[1] = 1;
    for(int i = 2; i <= m; i++)
        d[i] = d[i - 1] * 2;
    bool fix = false;
    if(abs(X[1] + Y[1]) % 2 == 0)
    {
        m++;
        d[m] = 1;
        fix = true;
    }
    cout << m << "\n";
    for(int i = 1; i <= m; i++)
        cout << d[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++)
    {
        x[m] = X[i];
        y[m] = Y[i];
        string ans = "";
        ll p2 = 1;
        for(int j = 1; j <= m - 1; j++)
            p2 *= 2;
        for(int j = m - 1; j >= 0; j--)
        {
            x[j] = x[j + 1];
            y[j] = y[j + 1];
            if(abs(x[j] - d[j + 1]) + abs(y[j]) <= p2 - 1 + fix)
            {
                ans += "R";
                x[j] -= d[j + 1];
            }
            else if(abs(x[j] + d[j + 1]) + abs(y[j]) <= p2 - 1 + fix)
            {
                ans += "L";
                x[j] += d[j + 1];
            }
            else if(abs(y[j] - d[j + 1]) + abs(x[j]) <= p2 - 1 + fix)
            {
                ans += "U";
                y[j] -= d[j + 1];
            }
            else if(abs(y[j] + d[j + 1]) + abs(x[j]) <= p2 - 1 + fix)
            {
                ans += "D";
                y[j] += d[j + 1];
            }
            p2 /= 2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
