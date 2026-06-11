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
ll a, b, c, k;
int main() {
    cin >> a >> b >> c >> k;
    vector<ll> v = {a, b, c};
    sort(v.rbegin(), v.rend());
    while (k) {
        v[0] *= 2;
        --k;
    }
    cout << accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
}
