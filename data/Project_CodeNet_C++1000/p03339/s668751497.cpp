#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = 0;
    right[n - 1] = 0;
    for (int i = 1; i < n; i++) {
        left[i] += left[i - 1];
        if (s[i - 1] == 'W') left[i]++;
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] += right[i + 1];
        if (s[i + 1] == 'E') right[i]++;
    }
    int ans = MAX;
    for (int i = 0; i < n; i++) {
        chmin(ans, left[i] + right[i]);
    }
    cout << ans << endl;
    return 0;
}