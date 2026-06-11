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
int n;

int main() {
    cin >> n;
    int ans = 1;
    while ((ans + 1) * (ans + 1) <= n) {
        ans += 1;
    }
    cout << ans * ans << endl;
    return 0;
}
