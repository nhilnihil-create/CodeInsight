#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i,N) cin >> h.at(i);
    h.push_back(0);
    int ans = 0;
    int left;
    rep(i,N+1) {
        if (h.at(i) > 0) {
            int minimum = h.at(i);
            left = i;
            ++i;
            for (; i < N + 1; ++i) {
                if (h.at(i) == 0) {
                    ans += minimum;
                    for (int j = left; j < i; ++j) {
                        h.at(j) -= minimum;
                    }
                    i = left - 1;
                    break;
                }
                minimum = min(minimum, h.at(i));
            }
        }
    }
    cout << ans << endl;
}
