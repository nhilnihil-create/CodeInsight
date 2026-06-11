#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int res = 0;
    sort(v.rbegin(), v.rend());
    int alice = 0, bob = 0;
    rep(i, n) {
        if (i % 2 == 0) alice += v[i];
        else bob += v[i];
    }
    cout << alice - bob << endl;
    return 0;
}