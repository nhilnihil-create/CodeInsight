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


int main() {

    ll N;

    cin >> N;

    ll count = 0, a;
    vector<ll> A(N + 1);

    rep(i, N + 1) {
        A[i] = 0;
    }

    rep(i, N) {
        cin >> a;
        if (a > N) {
            count++;
        }
        else if (A[a] < a) {
            A[a]++;
        }
        else {
            count++;
        }
    }

    rep(i, N + 1) {
        if (A[i] < i) {
            count += A[i];
        }
    }

    cout << count;

    return 0;
}