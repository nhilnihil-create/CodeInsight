#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int h,w,d,q;
    cin >> h >> w >> d;
    int a[h][w];
    map<int, pair<int, int>> mp;
    rep(i, h)
    {
        rep(j,w){
            cin >> a[i][j];
            a[i][j]--;
            mp[a[i][j]] = make_pair(i, j);
        }
    }
    cin >> q;
    int sum[200005] = {};
    rep(i,d){
        sum[i] = 0;
        auto start = mp[i];
        for (int j = i + d; j < h * w; j += d)
        {
            auto stop = mp[j];
            sum[j] = sum[j - d] + abs(stop.first - start.first) + abs(stop.second - start.second);
            start = stop;
        }
    }
    ll ans = 0;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        cout << sum[r] - sum[l] << endl;
    }
}