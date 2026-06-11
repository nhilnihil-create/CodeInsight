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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> A(M);
    rep(i, M) cin >> A[i];

    vector<bool> Amap(N + 1);
    rep(i, N + 1) {
        rep(j, M) {
            if (A[j] == i) {
                Amap[i] = true;
                break;
            }
        }
    }

    int a1 = 0;
    int a2 = 0;
    rep(i, X) {
        if (Amap[i]) a1++;
    }

    reps(i, X, N + 1) {
        if (Amap[i]) a2++;
    }

    // rep(i, N + 1) { cout << Amap[i]; }
    // cout << endl;
    cout << min(a1, a2) << endl;

    return 0;
}