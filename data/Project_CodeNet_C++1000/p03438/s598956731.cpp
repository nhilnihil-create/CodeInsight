#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] < b[i]) {
            cnt += (b[i] - a[i]) / 2;
        } else {
            cnt -= a[i] - b[i];
        }
    }

    if (cnt >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
