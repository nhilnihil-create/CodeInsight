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

int a, b, c;
int main() {
    cin >> a >> b >> c;
    int m1 = a, m2 = b;
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    cout << a * b / 2 << endl;
    return 0;
}
