#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    map<char, int> mp;
    mp['a'] = mp['b'] = mp['c'] = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s[j] == 'A' && s[j + 1] == 'B')
            {
                ++ans;
                s[j] = ':';
                s[j + 1] = ':';
            }
        }
        if (s[0] == 'B' && s[s.size() - 1] == 'A')
        {
            mp['c']++;
        }
        else if (s[0] == 'B')
        {
            mp['b']++;
        }
        else if (s[s.size() - 1] == 'A')
        {
            mp['a']++;
        }
    }
    // cout << ans << endl;
    // cout << "a:" << mp['a'] << endl;
    // cout << "b:" << mp['b'] << endl;
    // cout << "c:" << mp['c'] << endl;

    /* ========== */
    if (min(mp['a'], mp['b']) >= mp['c'])
    {
        mp['a'] -= mp['c'];
        mp['b'] -= mp['c'];
        ans += mp['c'] * 2;
        ans += min(mp['a'], mp['b']);
    }
    else
    {
        int x = min(mp['a'], mp['b']); // 小さい方
        int y = max(mp['a'], mp['b']); // 大きい方
        if (x == 0)
        {
            if (y > 0 && mp['c'] > 0)
            {
                ans += mp['c'];
            }
            else if (mp['c'] > 0)
            {
                ans += (mp['c'] - 1);
            }
        }
        else
        {
            ans += (x * 2);
            y -= x;
            mp['c'] -= x;
            if (mp['c'] > 0)
            {
                ans += mp['c'];
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}