#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    for (ll i = 1; i <= K; i++) {
        if (i % 2 == 1) {
            if (A == 0) break;

            if (A % 2 == 1) {
                A -= 1;
            }
            B += A / 2;
            A /= 2;
        } else {
            if (B == 0) break;
            if (B % 2 == 1) {
                B -= 1;
            }
            A += B / 2;
            B /= 2;
        }
    }
    cout << A << " " << B << endl;

    return 0;
}