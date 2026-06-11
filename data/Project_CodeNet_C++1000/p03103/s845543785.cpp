#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int cnt = 0;
    int cnt_1 = 0;
    int idx = 0;
    ll ans = 0;
    while(cnt < m){
        ans += a[cnt_1].first;
        idx++;
        if(idx >= a[cnt_1].second) {
            cnt_1++;
            idx = 0;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
