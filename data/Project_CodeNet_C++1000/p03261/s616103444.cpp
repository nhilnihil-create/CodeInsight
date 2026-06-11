#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<string> v(n);
    map<string, int> mp;
    bool flag = true;
    rep(i, n) cin >> v[i], mp[v[i]]++;
    rep(i, n - 1)
    {
        if (v[i][v[i].size() - 1] != v[i + 1][0])
            flag = false;
    }
    for (auto i : mp)
    {
        if (i.second != 1)
            flag = false;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
