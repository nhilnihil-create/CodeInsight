#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int D, G, p, c;
    cin >> D >> G;
    vector<tuple<int,int,int>> point(D);
    rep(i,D) {
        cin >> p >> c;
        point.at(i) = make_tuple(p, c, (i+1)*100);
    }
    reverse(point.begin(), point.end());
    int ans = INFINITY;
    for (int bit = 0; bit < (1<<D); ++bit) {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < D; ++i) {
            if (bit & (1<<i)) {
                sum += get<0>(point.at(i)) * get<2>(point.at(i)) + get<1>(point.at(i));
                cnt += get<0>(point.at(i));
            }
        }
        if (sum < G) {
            bool ok = false;
            for (int i = 0; i < D; ++i) {
                if ((bit & (1<<i)) == 0) {
                    if ((G - sum) / get<2>(point.at(i)) < get<0>(point.at(i))) {
                        cnt += (G - sum - 1) / get<2>(point.at(i)) + 1;
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) continue;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

