#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int next_combination(int sub)
{
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main()
{
    int n;
    cin >> n;
    v<int> N(5, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        switch (s[0])
        {
        case 'M':
            N[0]++;
            break;
        case 'A':
            N[1]++;
            break;
        case 'R':
            N[2]++;
            break;
        case 'C':
            N[3]++;
            break;
        case 'H':
            N[4]++;
            break;
        default:
            break;
        }
    }
    int bit = (1 << 3) - 1;
    ll ans = 0;
    for (; bit < (1 << 5); bit = next_combination(bit))
    {
        int c = 0;
        ll num = 1;
        for (int i = 0; i < 5; i++)
        {
            if (bit & (1 << i))
            {
                if (N[i] == 0)
                {
                    c++;
                }
                
                num *= N[i];

                if (c == 3)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        ans += num;
    }

    cout << ans << endl;
    return 0;
}