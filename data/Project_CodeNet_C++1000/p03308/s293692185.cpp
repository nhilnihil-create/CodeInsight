#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;
int main() {
    fastIO;
    int n;
    cin >> n;
    vector<lint> A(n);
    rep(i, n) cin >> A.at(i);

    lint diff = -1;
    for (size_t i = 0; i < A.size() - 1; i++) {
        for (size_t j = i + 1; j < A.size(); j++) {
            diff = max(diff, abs(A.at(i) - A.at(j)));
        }
    }
    cout << diff << endl;
}
