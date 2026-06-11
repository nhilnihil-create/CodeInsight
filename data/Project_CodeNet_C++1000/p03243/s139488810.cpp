#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    vector<int> abc;
    for (int i = 111; i <= 999; i += 111) {
        abc.push_back(i);
    }

    for (size_t i = 0; i < abc.size(); i++) {
        if (abc.at(i) >= n) {
            cout << abc.at(i) << endl;
            return 0;
        }
    }
}