#include <bits/stdc++.h>
using namespace std;

int xyecoc (int i, int j, vector < pair < int, int > > &a, vector < pair < int, int > > &b) {
    if (i >= 0 && j >= 0) {
        if (a[i].second != b[j].second)
            return a[i].first + b[j].first;
        return 0;
    }
    return 0;
}

signed main () {
    int n;
    cin >> n;
    map < int, int > odd, even;
    int odd_cnt = 0, even_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i & 1) {
            ++odd[x];
            ++odd_cnt;
        }
        else {
            ++even[x];
            ++even_cnt;
        }
    }
    vector < pair < int, int > > odd_prior, even_prior;
    for (auto pr: odd)
        odd_prior.push_back(make_pair(pr.second, pr.first));
    sort(odd_prior.begin(), odd_prior.end());
    for (auto pr: even)
        even_prior.push_back(make_pair(pr.second, pr.first));
    sort(even_prior.begin(), even_prior.end());
    int res = max({xyecoc(even_prior.size() - 1, odd_prior.size() - 1, even_prior, odd_prior), xyecoc(even_prior.size() - 1, odd_prior.size() - 2, even_prior, odd_prior), xyecoc(even_prior.size() - 2, odd_prior.size() - 1, even_prior, odd_prior)});
    if (res == 0)
        res = max(even_prior.back().first, odd_prior.back().first);
    cout << odd_cnt + even_cnt - res << '\n';
}
