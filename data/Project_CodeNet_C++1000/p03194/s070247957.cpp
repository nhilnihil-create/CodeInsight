#include "bits/stdc++.h"
using namespace std;

int main() {
    long long N, P;
    cin >> N >> P;

    vector<pair<long long, long long>> res = {};
    long long Q = P;
    for (int i = 2; i <= sqrt(P); i++) {
        int cnt = 0;
        while (Q % i == 0) {
            Q /= i;
            cnt++;
        }
        if (cnt > 0) {
            res.push_back(make_pair(cnt, i));
        }
    }
    res.push_back(make_pair(1, P));

    long long ans = 1;
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (res[i].first >= N) {
            ans *= pow(res[i].second, res[i].first / N);
        }
    }

    if (N > 1) {
        cout << ans << endl;
    }
    else {
        cout << P << endl;
    }
}