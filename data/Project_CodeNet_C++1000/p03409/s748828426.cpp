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
    vector<pair<int, int>> red(N), blue(N);
    vector<vector<int>> G(N, vector<int>());
    vector<bool> used(N, false);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        red[i] = {a, b};
    }

    rep(i, N) {
        int c, d;
        cin >> c >> d;
        blue[i] = {c, d};
    }

    sort(all(red), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    sort(all(blue),
         [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

    int cnt = 0;
    rep(i, N) {
        rep(j, N) {
            if (used[j])
                continue;
            if (blue[j].first > red[i].first &&
                blue[j].second > red[i].second) {
                used[j] = true;
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}