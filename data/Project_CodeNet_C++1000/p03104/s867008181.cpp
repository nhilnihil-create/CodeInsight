#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

ll oddsolve(ll a) { return (a + 1) / 2 % 2; }
ll solve(ll a) {
    if (a % 2 == 1)
        return oddsolve(a);
    else
        return oddsolve(a + 1) ^ (a + 1);
}

int main() {
    ll X, Y;
    cin >> X >> Y;
    cout << (solve(Y) ^ solve(X - 1)) << endl;
}