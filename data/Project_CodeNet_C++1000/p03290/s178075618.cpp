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
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];

    // 3進数を作成する
    // 0: 使用しない，1:中途半端に使用する，2:完全に使用する
    int num = pow(3, d);
    int ans = INF;
    for (int i = 0; i < num; i++)
    {
        int cp = i;
        vector<int> bit;
        for (int j = 0; j < d; j++)
        {
            int tmp = cp % 3;
            cp /= 3;
            bit.push_back(tmp);
        }
        map<int, int> mp;
        for (int b : bit)
        {
            mp[b]++;
        }
        if (mp[1] > 1)
        {
            continue;
        }
        int total = 0, pts = 0;
        for (int j = 0; j < d; j++)
        {
            if (bit[j] == 2)
            {
                total += (j + 1) * 100 * p[j] + c[j];
                pts += p[j];
            }
        }
        if (g > total)
        {
            int pt = 0;
            for (int j = 0; j < d; j++)
            {
                if (bit[j] == 1)
                {
                    pt = (((g - total) + ((j + 1) * 100) - 1)) / ((j + 1) * 100);
                    if (pt > p[j])
                    {
                        break;
                    }
                    total += (pt * 100 * (j + 1));
                    pts += pt;
                    break;
                }
            }
        }
        if (total >= g)
        {
            ans = min(ans, pts);
        }
    }
    cout << ans << endl;
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
