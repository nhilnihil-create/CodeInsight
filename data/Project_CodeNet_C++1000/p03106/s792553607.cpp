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


int a, b, k, cnt;
int main() {
    cin >> a >> b >> k;
    for (int i = min(a, b); i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            ++cnt;
            if (cnt == k) {
                cout << i << endl;
                exit(0);
            }
        }
    }

    return 0;
}
