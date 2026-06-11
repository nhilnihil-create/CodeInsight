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
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    ll ans = -1;

    ll L = N / __gcd(N, M) * M;
    ll a = L / N;
    ll b = L / M;
    ll c = a / __gcd(a, b) * b;
    ll d = c / a;
    ll e = c / b;

    bool flg = true;
    for (ll k = 0; k < min(N / d, M / e); k++) {
        if (S[k * d] != T[k * e]) {
            flg = false;
            break;
        }
    }

    if (flg)
        cout << L << endl;
    else
        cout << "-1" << endl;

    return 0;
}