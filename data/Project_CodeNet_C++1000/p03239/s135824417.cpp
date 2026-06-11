#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> c(n, vector<int> (2));
    rep(i, n) cin >> c[i][0] >> c[i][1];
    int mi = 10000;
    rep(i, n) {
        if(c[i][1] <= t) mi = min(mi, c[i][0]);
    }
    if(mi != 10000) cout << mi << endl;
    else cout << "TLE" << endl;
}