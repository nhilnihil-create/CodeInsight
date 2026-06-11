#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

vector<bool> hours;

int calc_min_diff() {
    int ret = 24;
    rep(i, 24) {
        rep(j, 24) {
            if (i == j) continue;
            if (hours[i] && hours[j]) {
                int d1 = abs(i - j);
                int d2 = 24 - d1;
                chmin(ret, min(d1, d2));
            }
        }
    }
    return ret;
}

int main() {
    hours.resize(24);
    hours[0] = true;
    
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, N) cin >> D[i];
    vector<int> cnt(13, 0);
    rep(i, N) cnt[D[i]]++;

    if (cnt[0] || cnt[12] >= 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> one_cnt_hours;
    for (int i = 1; i < 12; i++) {
        if (cnt[i] == 1) one_cnt_hours.push_back(i);
        else if (cnt[i] == 2) hours[i] = hours[24 - i] = true;
        else if (cnt[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (cnt[12]) hours[12] = true;

    if (one_cnt_hours.size() == 0) {
        cout << calc_min_diff() << endl;
        return 0;
    }

    int ans = 0;
    int m = one_cnt_hours.size();
    rep(bit, 1 << m) {
        rep(i, m) {
            int hour = one_cnt_hours[i];
            if (bit >> i & 1) {
                hours[hour] = true;
                hours[24 - hour] = false;
            } else {
                hours[hour] = false;
                hours[24 - hour] = true;
            }
        }
        chmax(ans, calc_min_diff());
    }
    cout << ans << endl;
}