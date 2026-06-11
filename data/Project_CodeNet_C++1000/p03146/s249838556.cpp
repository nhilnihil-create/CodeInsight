#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int collatz(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

int main() {
    fastIO;

    int n;
    cin >> n;

    map<int, int> mp;
    int idx = 1;

    while (true) {
        if (mp.find(n) != mp.end()) {
            cout << idx << endl;
            return 0;
        } else {
            mp[n] = idx++;
        }
        n = collatz(n);
    }
}
