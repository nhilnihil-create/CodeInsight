#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> cnt(501, vector<ll>(501, 0)), acc(501, vector<ll>(501, 0));
    rep(i, 0, M){
        ll l, r;
        cin >> l >> r;
        cnt[l][r-l]++;
    }
    rep(i, 0, 501){
        acc[i][0] = cnt[i][0];
        rep(j, 1, 501){
            acc[i][j] = acc[i][j-1] + cnt[i][j];
        }
    }
    rep(i, 0, Q){
        ll p, q;
        cin >> p >> q;
        ll res = 0;
        rep(i, p, q+1){
            res += acc[i][q-i];
        }
        cout << res << "\n";
    }
    return 0;
}