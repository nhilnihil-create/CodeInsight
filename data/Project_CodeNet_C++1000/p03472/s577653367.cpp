#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    lint N, H;
    cin >> N >> H;
    vector<pair<lint, lint>> sord(N);
    rep(i, N) cin >> sord[i].first >> sord[i].second;
    sort(sord.rbegin(), sord.rend());

    // rep(i, sord.size()) {
    //     cout << sord[i].first << ' ' << sord[i].second << endl;
    // }

    pair<lint, lint> sordSP = sord.front();
    sord.erase(sord.begin());

    vector<lint> th(0);

    for (int i = 0; i < sord.size(); i++) {
        if (sord[i].second <= sordSP.first) {
            continue;
        } else {
            th.push_back(sord[i].second);
        }
    }
    sort(th.rbegin(), th.rend());

    lint cnt = 0;
    for (int i = 0; i < th.size(); i++) {
        if (H <= sordSP.second) {
            cnt++;
            cout << cnt << endl;
            return 0;
        } else {
            H -= th[i];
            cnt++;
        }
    }

    H -= sordSP.second;
    cnt++;

    cnt += (H + sordSP.first - 1) / sordSP.first;
    cout << cnt << endl;
    return 0;
}