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
#define P pair<ll, ll>
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<P> que(m);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        que[i].first = a, que[i].second = b;
    }
    sort(all(que));
    ll ans = 1;
    P tmp = {que[0].first, que[0].second};
    rep(i, 0, m - 1)
    {
        if (tmp.second <= que[i + 1].first)
            ans++, tmp.first = que[i + 1].first, tmp.second = que[i + 1].second;
        else
            tmp.first = max(tmp.first, que[i + 1].first), tmp.second = min(tmp.second, que[i + 1].second);
    }
    cout << ans << endl;
}