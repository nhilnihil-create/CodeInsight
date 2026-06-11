#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n;
int main() {
    cin >> n;
    if (n & 1) {
        n -= 1;
        n /= 2;
        cout << n * (n + 1) << endl;
    } else {
        n /= 2;
        cout << n * n << endl;
    }
    return 0;
}
