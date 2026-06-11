#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000
#define PI 3.14159265359

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll diff_sum = 0, amari = 0, cnt = 0;
    vector<ll> amaris;
    rep(i, N) { cin >> A[i]; }

    rep(i, N) { cin >> B[i]; }

    rep(i, N) {
        if (B[i] > A[i]) {
            diff_sum += B[i] - A[i];
            cnt++;
        } else {
            amari += A[i] - B[i];
            amaris.push_back(A[i] - B[i]);
        }
    }

    if (amari >= diff_sum) {
        sort(all(amaris), greater<ll>());
        if (diff_sum == 0) {
            cout << cnt << endl;
            return 0;
        }
        rep(i, amaris.size()) {
            diff_sum -= amaris[i];
            cnt++;
            if (diff_sum <= 0) {
                break;
            }
        }

        cout << cnt << endl;
        return 0;
    } else {
        cout << -1 << endl;
        return 0;
    }
}