#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> left, right;
    int max_cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            left.insert(s.at(j));
        }

        for (int k = i; k < n; k++) {
            right.insert(s.at(k));
        }

        // counting
        int cnt = 0;
        for (auto l : left) {
            if (right.find(l) != right.end())
                cnt++;
        }
        max_cnt = max(max_cnt, cnt);

        // init
        cnt = 0;
        left.clear();
        right.clear();
    }

    cout << max_cnt << endl;
}
