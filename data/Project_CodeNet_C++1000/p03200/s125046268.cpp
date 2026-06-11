#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    int W = 0, B = 0;
    vector<int> place(N);
    rep(i, N) {
        if (S[i] == 'W') {
            place[i] = W;
            ++W;
        }
    }
    ll ans = 0;
    rep(i, N) {
        if (S[i] == 'W') ans += i - place[i];
    }
    cout << ans << endl;
}