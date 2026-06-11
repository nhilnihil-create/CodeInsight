#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<int, int>> res;
    if (N % 2 == 0) {
        int dame = 1;
        int st = N;
        while (st != 0) {
            for (int i = 1; i <= N; i++) {
                if (i == dame || st >= i)
                    continue;
                res.push_back({st, i});
            }
            st--;
            dame++;
        }
    } else {
        int dame = 0;
        int st = N;
        while (st != 0) {
            for (int i = 1; i <= N; i++) {
                if (st == N)
                    continue;
                if (i == dame || st >= i)
                    continue;
                res.push_back({st, i});
            }
            st--;
            dame++;
        }
    }

    cout << res.size() << endl;
    for (auto r : res) {
        cout << r.first << " " << r.second << endl;
    }
}