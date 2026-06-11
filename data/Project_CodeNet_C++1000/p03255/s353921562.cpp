/*
// 部分点解法
#include<iostream>
#define INF (1LL << 62)
#define MAX_N 2 * 100001
using namespace std;
typedef unsigned long long ll;

ll x[MAX_N];

ll calc_cost(ll i, ll a) {
    if (i == 1) return 5 * a;
    else return (2 * i + 1) * a;
}

int main() {
    ll N, X;
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> x[i];
    ll min_cost = INF;
    for (int k = 1; k <= N; k++) {
        ll now_cost = (N + k) * X;
        for (int i = 1; i <= N; i++) {
            now_cost += calc_cost((i + k - 1) / k, x[N - i + 1]);
        }
        min_cost = min(min_cost, now_cost);
    }
    cout << min_cost << endl;
    return 0;
}
*/

// 満点解法
#include<iostream>
#define MAX_N 2 * 2 * 100001
#define INF (1LL << 62)
using namespace std;
typedef long long ll;

ll x[MAX_N];

ll calc_cost(ll i, ll a) {
    if (i == 1) return 5 * a;
    else return (2 * i + 1) * a;
}

int main() {
    ll N, X;
    cin >> N >> X;
    x[N + 1] = 0;
    for (int i = N; i >= 1; i--) {
        cin >> x[i];
        x[i] += x[i + 1];
    }
    for (int i = N + 1; i <= 2 * N; i++) x[i] = 0;
    ll min_cost = INF;
    for (int k = 1; k <= N; k++) {
        ll now_cost = (N + k) * X;
        for (int i = 1; i <= (N + k - 1) / k; i++) {
            now_cost += calc_cost(i, x[k * (i - 1) + 1] - x[k * i + 1]);
            if (now_cost < 0) {
                now_cost = min_cost;
                break;
            }
        }
        min_cost = min(min_cost, now_cost);
    }
    cout << min_cost << endl;
    return 0;
}