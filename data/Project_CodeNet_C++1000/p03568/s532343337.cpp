#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n, a, res = 1, exep = 0;
    cin >> n;
    rep(i, n) {
        cin >> a;
        if (a % 2 == 0)res *= 2;
    }
    cout << pow(3, n) - res << endl;
    return 0;

}
