#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    vector<int> antenna(5);
    rep(i, 5) cin >> antenna.at(i);
    sort(antenna.begin(), antenna.end());

    int dist;
    cin >> dist;
    if (dist >= antenna.back() - antenna.front())
        cout << "Yay!";
    else
        cout << ":(";
}