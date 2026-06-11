#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    map<int, int> ma0, ma1;
    rep(i, N) {
        cin >> v[i];
        if (i % 2 == 0)
            ma0[v[i]]++;
        else
            ma1[v[i]]++;
    }

    vector<pair<int, int>> cnt0, cnt1;

    for (auto m : ma0) {
        cnt0.push_back({m.second, m.first});
    }

    for (auto m : ma1) {
        cnt1.push_back({m.second, m.first});
    }

    sort(all(cnt0), greater<pair<int, int>>());
    sort(all(cnt1), greater<pair<int, int>>());

    int ans;
    if (cnt0[0].second != cnt1[0].second)
        ans = N - (cnt0[0].first + cnt1[0].first);
    else if (cnt0.size() >= 2 && cnt1.size() >= 2) {
        if (cnt0[1].first >= cnt1[1].first)
            ans = N - (cnt0[1].first + cnt1[0].first);
        else
            ans = N - (cnt0[0].first + cnt1[1].first);
    } else if (cnt0.size() >= 2 && cnt1.size() == 1) {
        ans = N - (cnt0[1].first + cnt1[0].first);
    } else if (cnt0.size() == 1 && cnt1.size() >= 2) {
        ans = N - (cnt0[0].first + cnt1[1].first);
    } else {
        ans = N - (max(cnt0[0].first, cnt1[0].first));
    }

    cout << ans << endl;
}