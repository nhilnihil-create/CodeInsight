#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> v(m);
    rep(i, m)
    {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int last = 0;
    int ans = 0;
    for (auto p : v)
    {
        if (p.second > last)
        {
            last = p.first - 1;
            ans++;
        }
    }
    cout << ans << endl;
}