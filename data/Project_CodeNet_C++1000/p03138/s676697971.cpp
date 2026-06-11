#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    ll res = 0;

    for (int d = 60; d >= -1; d--) {
        if (d != -1 && !(K & (1LL << d)))
            continue;

        ll tmp = 0;
        for (int e = 60; e >= 0; e--) {
            ll mask = 1LL << e;
            int num = 0;
            rep(i, N) if (A[i] & mask) num++;

            if (e > d) {
                if (K & mask)
                    tmp += mask * (N - num);
                else
                    tmp += mask * num;
            } else if (e == d) {
                tmp += mask * num;
            } else {
                tmp += mask * max(num, N - num);
            }
        }
        res = max(res, tmp);
    }

    cout << res << endl;
}