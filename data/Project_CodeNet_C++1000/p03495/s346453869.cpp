#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    vector<int> ck;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        ck.push_back(itr->second);
    }

    sort(all(ck));

    int ans = 0;

    int re = mp.size() - k;
    if (re > 0)
    {
        rep(i, re)
        {
            ans += ck[i];
        }
    }

    cout << ans << endl;

    return 0;
}
