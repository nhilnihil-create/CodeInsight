#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    if (n == 0)cout << a - b << endl;
    else if (n % 2 == 1)cout << -a + b << endl;
    else if (n % 2 == 0)cout << a - b << endl;
    return 0;
}