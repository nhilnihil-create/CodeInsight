#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T, A;
    cin >> N >> T >> A;
    vector<double> temp(N);
    rep(i, N) {
        double h;
        cin >> h;
        temp[i] = T - h * 0.006;
    }

    double diff = 1e9;
    int ans = -1;

    rep(i, N) {
        if (diff > abs(A - temp[i])) {
            diff = abs(A - temp[i]);
            ans = i + 1;
        }
    }

    cout << ans << endl;
}