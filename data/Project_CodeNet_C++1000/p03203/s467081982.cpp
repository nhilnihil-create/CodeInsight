#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<P> d(n);
    set<P> st;
    rep(i, 0, n){
        int y, x;
        cin >> y >> x;
        y--; x--;
        d[i] = {y, x};
        st.insert({y, x});
    }
    sort(d.begin(), d.end());
    vector<int> yoko(h);
    yoko[0] = 0;
    rep(i, 1, h - 1){
        yoko[i] = yoko[i - 1];
        if(yoko[i] != w - 1){
            if(!st.count({i, yoko[i - 1] + 1})){
                yoko[i]++;
            }
        }
    }
    int ans = h;
    rep(i, 0, n){
        if(d[i].first == 0) continue;
        if(yoko[d[i].first - 1] >= d[i].second){
            ans = min(ans, d[i].first);
        }
    }
    cout << ans << endl;
}