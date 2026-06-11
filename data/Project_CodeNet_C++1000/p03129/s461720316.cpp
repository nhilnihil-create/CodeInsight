#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    string ans = "NO";
    if ((n + 1) / 2 >= k) ans = "YES";
    cout << ans << endl;
}