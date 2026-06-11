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
    int t[110], v[110];
    rep(i, N) cin >> t[i];
    int sum = 0;
    rep(i, N) sum += t[i];
    rep(i, N) cin >> v[i];
    int s[40010];
    rep(i, 40010) {
        s[i] = INF;
    }
    s[0] = 0;
    int T = 0;
    rep(i, N) {
        for(int j = T; j < T + t[i] * 2; j += 2) {
            s[j + 1] = min({s[j + 1], v[i] * 2, s[j] + 1}); 
            s[j + 2] = min({s[j + 2], v[i] * 2, s[j] + 2}); 
        }
        T += t[i] * 2;
    }
    //rep(i, sum * 2 + 1) cout << fixed << setprecision(1) << i/2.0 << " " << s[i]/2.0 << endl;
    //cout << endl;
    T = sum * 2;
    s[sum * 2] = 0;
    RREP(i, N - 1, 0) {
        for(int j = T; j > T - t[i] * 2; j -= 2) {
            s[j - 1] = min({s[j - 1], v[i] * 2, s[j] + 1});
            s[j - 2] = min({s[j - 2], v[i] * 2, s[j] + 2}); 
        }
        T -= t[i] * 2;
    }
    int ans = 0;
    // rep(i, sum * 2 + 1) cout << fixed << setprecision(1) << i/2.0 << " " << s[i]/2.0 << endl;
    // cout << endl;
    rep(i, sum * 2 + 1) ans += s[i];
    cout << fixed << setprecision(12) << ans/4.0 << endl;

    return 0;
}
