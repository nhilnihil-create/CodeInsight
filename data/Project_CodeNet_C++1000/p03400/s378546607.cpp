#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ll N, D, X;
    cin >> N >> D >> X;
    for (int i = 0; i < N; i++) {
        ld a;
        cin >> a;
        X += ceil(D / a);
    }
    cout << X << endl;
}
