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
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int a[1010];
    rep(i, N) cin >> a[i];
    vector<int> v;

    // 連続する部分列の総和の全パターンを計算する。
    rep(i, N) {
        int sum = 0;
        REP(j, i, N - 1) {
            sum += a[j];
            v.push_back(sum);
        }
    }


    int ans = 0;
    // 最上位bit(最重要bit)から考えていく。
    // 注目しているbitが1にできるのならば、1を立てる。
    RREP(i, 50, 0) {
        vector<int> nx_v;
        rep(j, v.size()) {
            if (v[j] & (1LL << i)) nx_v.push_back(v[j]);
        }
        // 注目しているbitに対して、1が立っている個数がK個未満の時は何もしない。
        if(nx_v.size() < K) continue;

        ans += (1LL << i);
        v = nx_v;
    }

    cout << ans << endl;

    return 0;
}