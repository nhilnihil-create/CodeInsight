#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int cnt[13] = {};
    cnt[0]++;
    rep(i, N) {
        int x; cin >> x;
        x = min(x, 24 - x);
        cnt[x]++;
    }
    rep(i, 13) {
        if(cnt[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    rep(bit, (1 << 13)) {
        vector<int> v;
        rep(i, 13) {
            if(cnt[i] == 2) {
                v.push_back(i);
                v.push_back(24 - i);
            } else if(cnt[i] == 1){
                if(bit & (1 << i)) v.push_back(i);
                else v.push_back(24 - i);
            }
        }
        sort(v.begin(), v.end());
        int tmp = 24;
        rep(i, v.size()) {
            int d1 = v[i];
            int d2 = v[(i + 1) % v.size()];
            int d = abs(d2 - d1);
            tmp = min(tmp, min(d, 24 - d));
            //cout << d1 << " " << d2 << " " << d << " " << min(d, 24 - d) << endl;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;


    return 0;
}
