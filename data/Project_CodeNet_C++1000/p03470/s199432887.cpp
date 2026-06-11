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
    vector<int> Mochi(n);
    rep(i, n) cin >> Mochi.at(i);

    sort(Mochi.begin(), Mochi.end());

    int cnt = 1;
    for (size_t i = 0; i < Mochi.size() - 1; i++) {
        if (Mochi.at(i) != Mochi.at(i + 1))
            cnt++;
    }
    cout << cnt << endl;
}