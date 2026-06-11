#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (i == k - 1)
            cout << (char)(s.at(i) - 'A' + 'a');
        else
            cout << (char)s.at(i);
    }
}