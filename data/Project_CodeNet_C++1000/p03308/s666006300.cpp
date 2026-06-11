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
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);

    sort(A.begin(), A.end());
    int ans = A.at(N - 1) - A.at(0);

    cout << ans << endl;

    return 0;
}
