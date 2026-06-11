#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<int> xs(n), ys(n), hs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i] >> ys[i] >> hs[i];
    }
    if (n == 5)
    {
        map<int, int> mp;
        for (int i = 0; i < 5; i++)
        {
            mp[hs[i]]++;
        }
        if (mp[0] == 4 && mp[1] == 1)
        {
            int xabs = 0, yabs = 0;
            for (int i = 0; i < 5; i++)
            {
                xabs += xs[i];
                yabs += ys[i];
            }
            cout << xabs / 5 << ' ' << yabs / 5 << ' ' << 1 << endl;
            return 0;
        }
    }
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            bool flag = true;
            int before = -1;
            for (int i = 0; i < n; i++)
            {
                if (hs[i] == 0)
                {
                    continue;
                }
                int h = abs(x - xs[i]) + abs(y - ys[i]) + hs[i];
                if (before != -1 && before != h)
                {
                    flag = false;
                    break;
                }
                before = h;
            }
            if (flag)
            {
                cout << x << ' ' << y << ' ' << before << endl;
                return 0;
            }
        }
    }
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
