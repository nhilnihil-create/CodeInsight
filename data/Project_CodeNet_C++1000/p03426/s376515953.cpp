#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    map<int, pair<int, int>> mp;
    rep(i, h) rep(j, w) {
        int tmp_a;
        cin >> tmp_a;
        mp[tmp_a] = make_pair(i, j);
    }
    int q;
    cin >> q;
    vector<int> lv(q);
    vector<int> rv(q);
    rep(i, q) cin >> lv[i] >> rv[i];
    vector<vector<int>> modsum(d, vector<int>(h*w/d+10));
    int i = 0;
    while(1) {
        if ( i == d ) break;
        int j = 0;
        int tmp_p = i;
        while(1) {
            if ( tmp_p + d > h * w ) break;
            if ( j < 1 ) {
                modsum[i][j] = (abs(mp[tmp_p+d].first - mp[tmp_p].first) + abs(mp[tmp_p+d].second - mp[tmp_p].second));
            }
            else {
                modsum[i][j] = (modsum[i][j-1] + abs(mp[tmp_p+d].first - mp[tmp_p].first) + abs(mp[tmp_p+d].second - mp[tmp_p].second));
            }
            tmp_p += d;
            ++j;
        }
        ++i;
    }
//    rep(i, d) {
//        for ( auto tmp_modsum : modsum[i] ) {
//            printf("%d ", tmp_modsum);
//        } 
//        printf("\n");
//    }
    i = 0;
    while(1) {
        if ( i == q ) break;
        int ans = 0;
        int mod_p = lv[i] % d;
        int start_p = lv[i] / d;
        int end_p = rv[i] / d;
        if ( start_p < 1 ) cout << modsum[mod_p][end_p-1] << endl;
        else               cout << modsum[mod_p][end_p-1] - modsum[mod_p][start_p - 1] << endl;
        ++i;
    }
    return 0;
}
