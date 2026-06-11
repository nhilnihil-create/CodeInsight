#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

//メモ化再帰、DP
int memo[100100];

int rec (int n) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];

    int res = n;
    for (int pow6 = 1; pow6 <= n; pow6 *= 6) {
        res = min (res, rec (n - pow6) + 1);
    }
    for (int pow9 = 1; pow9 <= n; pow9 *= 9) {
        res = min (res, rec (n - pow9) + 1);
    }
    return memo[n] = res;
}

int main() {
    int n;
    cin >> n;
    rep (i, n + 1) memo[i] = -1;
    cout << rec (n) << "\n";
}
