#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;


int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll>s(a + 2), t(b + 2);
    rep(i, a)cin >> s[i + 1];
    rep(i, b)cin >> t[i + 1];
    s[0] = -1e12, t[0] = -1e12;
    s[a+1] = 1e12, t[b+1] = 1e12;
    vector<ll>ans(q);
    rep(i, q) {
        ll x, ms, mt;
        cin >> x;
        ll dis;
        int sit = lower_bound(s.begin(), s.end(), x) - s.begin();

        int tit = lower_bound(t.begin(), t.end(), x) - t.begin();
        dis = max(x - s[sit - 1], x - t[tit - 1]);

        ll cross;
        if (s[sit] > t[tit]) {
            dis = min(dis, s[sit] - x);
            cross = min(x - s[sit - 1], t[tit] - x) + (t[tit] - s[sit - 1]);
        }
        else {
            dis = min(dis, t[tit] - x);
            cross = min(s[sit]-x, x-t[tit - 1]) + (s[sit] - t[tit - 1]);
        }

        dis = min(dis, cross);
        ans[i]=dis;
    }
    
    rep(i, q)cout << ans[i] << endl;
    
    return 0;
}