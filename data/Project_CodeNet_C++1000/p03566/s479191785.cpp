#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    v.push_back(0);
    vector<int> st(n+1);
    rep(i, n) {
        st[i+1] = st[i] + t[i];
    }
    vector<int> speed(st.back()+1);
    rep(i, speed.size()) {
        if (i==0) continue;
        int res = speed[i-1] + 1;
        auto it = lower_bound(whole(st), i);
        it--;
        int num = it - st.begin();
        chmin(res, v[num]);
        for (int j=num+1; j<=n; j++) {
            int th = v[j] + (st[j]-i);
            chmin(res, th);
        }
        speed[i] = res;
        //cout << i << " " << res << endl;
    }
    double ans = 0.0;
    rep(i, speed.size()-1) {
        ans += 0.5 * (speed[i]+speed[i+1]);
        if (speed[i]==speed[i+1]) {
            auto it = upper_bound(whole(st), i);
            it--;
            int num = it - st.begin();
            if (speed[i]<v[num]) {
                ans += 0.25;
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}
