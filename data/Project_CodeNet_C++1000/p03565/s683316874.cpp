#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (n < m)
    {
        cout << "UNRESTORABLE" << endl;
    }
    else
    {
        bool ok = false;
        repi(i, n - m + 1, 0)
        {
            if (s[i] == t[0])
            {
                int cnt = 1;
                repi(j, m, 1)
                {
                    if (s[i + j] == t[j])
                        cnt++;
                }
                if (cnt == m)
                    ok = true;
            }
        }
        if (!ok)
        {
            for (int i = n - m; i >= 0; i--)
            {
                if (s[i] == t[0] || s[i] == '?')
                {
                    int cnt = 1;
                    repi(j, m, 1)
                    {
                        if (s[i + j] == t[j] || s[i + j] == '?')
                            cnt++;
                    }
                    if (cnt == m)
                    {
                        ok = true;
                        repi(j, m, 0)
                        {
                            s[i + j] = t[j];
                        }
                    }
                }
                if (ok)
                    break;
            }
            if (!ok)
            {
                cout << "UNRESTORABLE" << endl;
                return 0;
            }
        }
        repi(i, n, 0)
        {
            if (s[i] == '?')
                s[i] = 'a';
        }
        cout << s << endl;
    }
    return 0;
}