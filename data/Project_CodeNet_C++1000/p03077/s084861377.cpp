#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll N;
    cin >> N;

    ll neck = pow(10,15), tmp;

    rep(i, 5) {
        cin >> tmp;
        neck = min(neck, tmp);
    }

    ll ans = 5;
    if(neck != 1){
        cout << ans + N / neck;
    }
    else {
        cout << ans + N - 1;
    }
    return 0;
}
