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

int n, p;

int main() {
    cin >> n >> p;
    int s = n * 3 + p;
    cout << s / 2 << endl;
    return 0;
}
