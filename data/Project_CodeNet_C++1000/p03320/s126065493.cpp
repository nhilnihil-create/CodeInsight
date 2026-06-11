#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()

int digit_sum(ll num) {
    int res = 0;
    while (num > 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    ll K;
    cin >> K;

    ll x = 1, d = 1;
    while (K > 0) {
        cout << x << endl;
        ll nx1 = x + d;
        ll nx2 = x + d * 10;
        if (nx1 * digit_sum(nx2) > nx2 * digit_sum(nx1))
            d *= 10;
        x = x + d;
        K--;
    }
    return 0;
}