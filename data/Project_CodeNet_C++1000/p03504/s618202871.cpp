//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n, C;
    cin >> n >> C;
    vector<tuple<int, int, int> > stc(n);
    rep(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        stc[i] = make_tuple(s, t, c);
    }
    stc.push_back(make_tuple(0, 0, 0));
    sort(stc.begin(), stc.end());

    vector<pair<int, int> > dp(C, make_pair(0, 0));
    rep(i_, n) {
        int i = i_+1;
        rep(k, C) {
            dp[k].first -= get<0>(stc[i]) - get<0>(stc[i-1]);
        }
        rep(k, C) {
            if(dp[k].first > 0) {
                continue;
            } else if(!dp[k].first && get<2>(stc[i]) == dp[k].second) {
                dp[k].first = get<1>(stc[i]) - get<0>(stc[i]);
                break;
            } else if(dp[k].first < 0){
                dp[k].first = get<1>(stc[i]) - get<0>(stc[i]);
                dp[k].second = get<2>(stc[i]);
                break;
            }
        }
        
    }

    int ans = C;
    rep(i, C) {
        if(dp[i].first == -get<0>(stc[n])) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}