#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m, k, ans;

int main() {
    cin >> n;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (i * 4 + j * 7 == n) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
