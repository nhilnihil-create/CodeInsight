#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    rep(i, c) rep(j, c) cin >> d[i][j];
    vector<vector<int>> cv(n, vector<int>(n));
    map<int, int> mp_mod3_0;
    map<int, int> mp_mod3_1;
    map<int, int> mp_mod3_2;
    rep(i, n) rep(j, n) {
        cin >> cv[i][j];
        --cv[i][j];
        if ( ( i + j + 2 ) % 3 == 0 ) {
            ++mp_mod3_0[cv[i][j]];
        }
        else if ( ( i + j + 2 ) % 3 == 1 ) {
            ++mp_mod3_1[cv[i][j]];
        }
        else if ( ( i + j + 2 ) % 3 == 2 ) {
            ++mp_mod3_2[cv[i][j]];
        }
    }

    int ans = 1e9;
    rep(i, c) rep(j, c) rep(k, c) {
        if ( i == j || j == k || k == i ) continue;
        int tmp_ans = 0;
        if ( !mp_mod3_0.empty() ) {
            for ( auto tmp_mp : mp_mod3_0 ) {
                tmp_ans += d[tmp_mp.first][i] * tmp_mp.second;
            }
        }
        if ( !mp_mod3_1.empty() ) {
            for ( auto tmp_mp : mp_mod3_1 ) {
                tmp_ans += d[tmp_mp.first][j] * tmp_mp.second;
            }
        }
        if ( !mp_mod3_2.empty() ) {
            for ( auto tmp_mp : mp_mod3_2 ) {
                tmp_ans += d[tmp_mp.first][k] * tmp_mp.second;
            }
        }
//        cout << i << " " << tmp_ans << endl;
        ans = min(ans, tmp_ans);
    }

    cout << ans << endl;

    return 0;
}
