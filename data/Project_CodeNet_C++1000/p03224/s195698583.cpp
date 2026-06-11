#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int k = 1;
    while (true) {
        if (2 * N < k * (k - 1)) {
            cout << "No" << endl;
            return 0;
        }
        else if (2 * N == k * (k - 1)) break;
        ++k;
    }
    vector<vector<int>> s(k);
    int now = 1;
    rep(i, 0, k) {
        rep(j, i + 1, k) {
            s[i].push_back(now);
            s[j].push_back(now);
            ++now;
        }
    }
    cout << "Yes" << endl;
    cout << k << endl;
    rep(i, 0, k) {
        cout << s[i].size() << ' ';
        rep(j, 0, s[i].size()) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}