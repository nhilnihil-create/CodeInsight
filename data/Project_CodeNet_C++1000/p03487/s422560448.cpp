#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    int cnt = 0;
    for (auto x : m) {
        if (x.first > x.second) {
            cnt += x.second;
        } else {
            cnt += x.second - x.first;
        }
    }
    cout << cnt << endl;
}