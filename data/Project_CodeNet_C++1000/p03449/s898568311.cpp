#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;

int sum(vector<vector<int>> A, int N, int x) {
    int summation = 0;
    rep(i, x + 1) {
        summation += A.at(0).at(i);
    }
    repl(i, x, N) {
        summation += A.at(1).at(i);
    }
    return summation;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    rep(i, 2) {rep(j, N) cin >> A.at(i).at(j);}

    int Candies = 0, temp = 0;
    rep(x, N) Candies = max(Candies, sum(A, N, x));
    cout << Candies << endl;
    return 0;
}
