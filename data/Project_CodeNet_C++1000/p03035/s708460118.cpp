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

int a, b;
int main() {
    cin >> a >> b;
    if (a <= 5)
        cout << 0 << endl;
    else if (a <= 12)
        cout << b / 2 << endl;
    else
        cout << b << endl;

    return 0;
}
