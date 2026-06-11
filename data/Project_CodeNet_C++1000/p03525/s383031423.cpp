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

int cnt[13];
int X[25];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int D[51];
    rep(i, N) cin >> D[i];
    cnt[0]++;
    rep(i, N) cnt[D[i]]++;
    rep(i, 13) {
        if(cnt[i] == 2) {
            X[i]++;
            X[24 - i]++;
        }else if (cnt[i] > 2) {
            X[i] += 2;
            X[24 - i]++;
        }
    }
    vector<int> v;
    rep(i, 13) if(cnt[i] == 1) v.push_back(i);
    int size = v.size();
    sort(v.begin(), v.end());
    int ans = 0;
    rep(bit, (1 << size)) {
        int x[25];
        rep(i, 25) x[i] = X[i];
        rep(i, size){
            if (bit & (1 << i)) {
                x[24 - v[i]] = 1;
            } else {
                x[v[i]] = 1;
            }
        }
        int tmp = 24;
        rep(i, 25) {
            rep(j, 25) {
                if (i == j) continue;
                int d = abs(i - j);
                if (x[i] && x[j])
                    tmp = min(tmp, min(d, 24 - d));
                if (x[i] >= 2) tmp = 0;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
