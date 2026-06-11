#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for (int i = 0; i < n; ++i) cin >> m[i];
    int sum = accumulate(m.begin(), m.end(), 0);
    x -= sum;
    sort(m.begin(), m.end());
    int tmp = x / m[0];
    cout << tmp + n << endl;
    return 0;
}