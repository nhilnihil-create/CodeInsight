#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K; cin >> N >> K;
    vector<pair<int, int>> xy(N);
    for (int i = 0; i < N; i++) cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(), xy.end());

    ll ans = LLONG_MAX;
    for (int i = 0; i < N-1; i++) {
        for (int j = i + K - 1; j < N; j++) {
            ll dx = xy[j].first - xy[i].first;
            vector<int> y;
            for (int m = i; m <= j; m++) {
                y.push_back(xy[m].second);
            }
            sort(y.begin(), y.end());
            for (int m = 0; m + K - 1 < y.size(); m++) {
                int n = m + K - 1;
                ll a = dx * (y[n] -y[m]);
                if (a < ans) ans = a;
            } 
        }
    }
    cout << ans << endl;
}