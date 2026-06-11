#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<char> S(N);
    rep(i, N) cin >> S.at(i);

    bool hasYellow = false;
    rep(i, N) {
        if (S.at(i) == 'Y') hasYellow = true;
    }
    string ans = hasYellow ? "Four" : "Three";

    cout << ans << endl;

    return 0;
}
