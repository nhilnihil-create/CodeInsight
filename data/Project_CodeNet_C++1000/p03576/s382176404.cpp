#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    int n, a;
    cin >> n >> a;
    vector<int64_t> x(n);
    vector<int64_t> y(n);
    vector<pair<int64_t, int64_t>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
        p.at(i) = make_pair(x.at(i), y.at(i));
    }

    sort(begin(x), end(x));
    sort(begin(y), end(y));
    int64_t ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    int64_t x_min = x.at(i);
                    int64_t x_max = x.at(j);
                    int64_t y_min = y.at(k);
                    int64_t y_max = y.at(l);
                    int cnt = 0;
                    for (int m = 0; m < n; m++) {
                        int64_t cur_x = p.at(m).first;
                        int64_t cur_y = p.at(m).second;
                        if (x_min <= cur_x && cur_x <= x_max && y_min <= cur_y && cur_y <= y_max) {
                            cnt++;
                        }
                    }
                    if (cnt >= a) {
                        int64_t area = (x_max - x_min) * (y_max - y_min);
                        chmin(ans, area);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}