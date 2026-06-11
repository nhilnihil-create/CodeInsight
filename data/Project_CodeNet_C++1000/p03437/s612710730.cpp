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
    ll A, B;
    cin >> A >> B;

    if (A % B == 0) {
        cout << "-1" << endl;
    } else {
        reps(i, 2, MAX_N) {
            if ((A * i) % B != 0) {
                cout << A * i << endl;
                break;
            }
        }
    }

    return 0;
}