#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    int d, g;
    cin >> d >> g;
    vector<ll> kazu(d), bonus(d);
    rep(i, 0, d) cin >> kazu[i] >> bonus[i];
    ll ans = INF;
    rep(i, 0, 1 << d)
    {
        vector<ll> tmp;
        vector<ll> num = kazu;
        rep(j, 0, d) if (i >> j & 1) tmp.push_back(j);
        int score = 0;
        ll qst = 0;
        for (auto j : tmp)
            score += 100 * (j + 1) * kazu[j] + bonus[j], qst += kazu[j], num[j] = 0;
        while (score < g)
        {
            int idx;
            rep(j, 0, d)
            {
                if (num[d - 1 - j] > 0)
                {
                    idx = d - 1 - j;
                    break;
                }
            }
            score += 100 * (idx + 1), qst++, num[idx]--;
            if (MX(num) == 0)
                break;
        }
        ans = min(ans, qst);
    }
    cout << ans << endl;
}
