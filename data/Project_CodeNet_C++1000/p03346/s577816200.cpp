#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

int main() {
    ll N, h=0;
    cin >> N;
    vector<ll> A(N+1, 0);
    for (ll i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        A[a]=A[a-1]+1;
        h=max(h, A[a]);
    }
    cout << N-h << endl;
}
