#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
ll A, B;


void input() {
    cin >> A >> B;
}


ll solve(ll x) {
    ll ret = 0;
    while ((x - 3) % 4 != 0) {
        ret ^= x;
        x--;
    }
    return ret;
}


int main() {
    input();
    ll ans = solve(A - 1) ^ solve(B);
    cout << ans << endl;
}
