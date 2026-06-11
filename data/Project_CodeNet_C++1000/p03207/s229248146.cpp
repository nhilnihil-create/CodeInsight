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
    vector<int> p(N);
    rep(i, N) cin >> p.at(i);

    sort(p.begin(), p.end());

    int sum = 0;
    rep(i, N - 1) {
        sum += p.at(i);
    }
    sum += p.at(N - 1) / 2;

    cout << sum << endl;

    return 0;
}
