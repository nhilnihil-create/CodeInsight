#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    vector<int> likes(m);
    rep(i, m) likes.at(i) = 0;

    rep(K, n) {
        int k;
        cin >> k;
        rep(i, k) {
            int a;
            cin >> a;
            likes.at(a - 1) += 1;
        }
    }

    int sum = 0;
    rep(i, m) {
        if (likes.at(i) == n)
            sum++;
    }
    cout << sum << endl;
}