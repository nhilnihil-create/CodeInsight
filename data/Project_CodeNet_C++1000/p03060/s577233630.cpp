#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<int> V(N), C(N);
    rep(i, N) cin >> V.at(i);
    rep(i, N) cin >> C.at(i);

    int sum = 0;
    rep(i, N) {
        if (V.at(i) - C.at(i) > 0) sum += V.at(i) - C.at(i);
    }

    cout << sum << endl;

    return 0;
}
