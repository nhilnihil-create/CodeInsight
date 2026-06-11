#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string, string>;
ll MOD = 1e9+7;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string t = s.substr(n, n);
    reverse(t.begin(), t.end());

    map<P, int> m;
    for(int i = 0; i < (1 << n); i++)
    {
        string red, blue;
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)
            {
                red.append(1, s[j]);
            }
            else
            {
                blue.append(1, s[j]);
            }
        }
        m[P(red, blue)]++;
    }
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++)
    {
        string red, blue;
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)
            {
                red.append(1, t[j]);
            }
            else
            {
                blue.append(1, t[j]);
            }
        }
        P p = P(red, blue);
        if(m.find(p) != m.end())
        {
            ans += m[p];
        }
    }
    cout << ans << endl;
}
