#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const vector<char> V = {'M', 'A', 'R', 'C', 'H'};

    int N;
    cin >> N;
    vector<ll> cnt(5, 0);
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        char &c = S.front();
        for (int j = 0; j < 5; ++j) {
            if (c == V.at(j)) {
                cnt.at(j)++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += cnt.at(i) * cnt.at(j) * cnt.at(k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}