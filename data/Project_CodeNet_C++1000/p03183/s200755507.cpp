#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())
#define we first.first
#define du first.second
#define be second

bool compareInterval(pair< pair<int, int>, int > l, pair< pair<int, int>, int > r) 
{
    return l.we+l.du < r.we+r.du;
}

int mx[20005] = {0};
vector< pair< pair<int, int>, int > > v;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int w, s, b;
        cin >> w >> s >> b;
        v.pb({{w, s}, b});
    }
    sort(v.begin(), v.end(), compareInterval);
    for(auto &k: v)
    {
        // cout << k.we << " " << k.du << " " << k.be << endl;
        for(int i = k.du; i >= 0; i--)
            mx[i+k.we] = max(mx[i+k.we], mx[i]+k.be);
    }
    int ans = 0;
    for(int i = 0; i < 20005; i++)
        ans = max(ans, mx[i]);
    cout << ans << endl;
}