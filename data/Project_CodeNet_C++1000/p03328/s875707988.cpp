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


int a, b;

int main() {
    cin >> a >> b;
    int c = b - a - 1;
    int sum = c * (c + 1) / 2;
    cout << sum - a << endl;
    return 0;
}
