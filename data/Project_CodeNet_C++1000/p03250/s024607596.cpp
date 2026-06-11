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

const int N = 1e5 + 5;
int n, m, k, ans;

int main() {
    cin >> n >> m >> k;
    vector<int> v = {n, m, k};
    sort(v.begin(), v.end(), greater<int>());
    cout << v[0] * 10 + v[1] + v[2] << endl;
    return 0;
}
