#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    ll X = 0;
    cin >> N;
    vector<ll>v(N);
    for (int i = 0; i < N; i++) {
        ll A, B;
        cin >> A >> B;
        X += B;
        v[i] = A+B;
    }
    sort(v.begin(), v.end(), greater<ll>());
    X *= -1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            X += v[i];
        }
    }
    cout << X << endl;
}
