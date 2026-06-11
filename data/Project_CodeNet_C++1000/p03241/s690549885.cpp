#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            vec.push_back (i);
            vec.push_back (m / i);
        }
    }
    int ans = 1;
    sort (vec.begin(), vec.end());
    rep (i, vec.size()) {
        int b = m / vec[i];
        //cout << vec[i] << " : " << b << "\n";
        if (b < n) break;
        ans = vec[i];
    }
    cout << ans << "\n";
}