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
const double x = 380000.0;
double a, sum;
string b;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (b == "JPY")
            sum += a;
        else
            sum += a * x;
    }
    cout << sum << endl;
    return 0;
}
