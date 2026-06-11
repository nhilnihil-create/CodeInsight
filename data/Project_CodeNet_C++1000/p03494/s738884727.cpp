#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = unsigned long long int;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;

    vector<int> A(n);
    rep(i, n) cin >> A.at(i);

    int cnt = 0;
    while (true) {
        for (size_t i = 0; i < A.size(); i++) {
            if (A.at(i) % 2 == 0) {
                A.at(i) /= 2;
            } else {
                cout << cnt << endl;
                return 0;
            }
        }
        cnt++;
    }
}